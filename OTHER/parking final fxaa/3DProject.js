import * as THREE from './jsm/three.module.js'
import * as dat from './jsm/dat.gui.module.js'
import * as echarts from './jsm/echarts.esm.min.js'
import * as jquery from './jsm/jquery-3.6.0.min.js'

import {EffectComposer} from './jsm/EffectComposer.js'
import {RenderPass} from './jsm/RenderPass.js'
import {ShaderPass} from './jsm/ShaderPass.js'
import {FXAAShader} from './jsm/FXAAShader.js'

import {OrbitControls} from './jsm/OrbitControls.js'
import {MTLLoader} from './jsm/MTLLoader.js'
import {OBJLoader} from './jsm/OBJLoader.js'

import SpriteText from './jsm/three-spritetext.module.js'
import Stats from './jsm/stats.module.js'

let scene, renderer, composer0, camera, controls, mtlLoader, objLoader;
let mouse, raycaster, intersects;
let stats = initStats();
let Label, Label1, Label2;
let objects = [];

init()
animate()

function init() {
    initCamera();
    initScene();
    initLight();
    initRender();
    initComposer();
    initFXAA();
    initSkybox();
    initControls();
    initGui();
    initEcharts();
    initContent();

    createFloor();
    addVideoPlane(0, 60, -690, 200, 100, scene, 'video');
    addArea(-210, 110, 200, 130, scene, "ID1$接驳巴士站", "FF0000", 5, "右对齐");
    addArea(-260, -160, 310, 180, scene, "ID1$安置地，留用地", "FF0000", 5, "右对齐");
    addArea(0, -160, 200, 180, scene, "ID1$白地", "FF0000", 5, "居中");
    initBuild('./models/3DProject/', '小区', 0.5, 0.8, 0.5, -140, 0, -90, 0, Math.PI / 2, 0);
    initBuild('./models/3DProject/', '车站', 1, 1, 1, -210, 0, 120, 0, 0, 0);

    raycaster = new THREE.Raycaster();
    mouse = new THREE.Vector2()

    window.addEventListener('resize', onWindowResize, false)
    window.addEventListener('click', onMouseClick, false);
}

function initCamera() {
    camera = new THREE.PerspectiveCamera(45, window.innerWidth / window.innerHeight, 0.1, 30000)
    camera.position.set(0, 100, 200);
}

function initScene() {
    scene = new THREE.Scene();
}

function initLight() {
    const directionalLight = new THREE.DirectionalLight(0xffffff, 0.3);
    directionalLight.color.setHSL(0.1, 1, 0.95);
    directionalLight.position.set(0, 200, 0).normalize();
    scene.add(directionalLight);

    const ambient = new THREE.AmbientLight(0xffffff, 1);
    ambient.position.set(0, 0, 0);
    scene.add(ambient);
}

function initRender() {
    renderer = new THREE.WebGLRenderer({antialias: true});
    renderer.setPixelRatio(window.devicePixelRatio);
    renderer.setSize(window.innerWidth, window.innerHeight);
    renderer.setClearColor(0x4682B4, 1.0);
    document.body.appendChild(renderer.domElement);
}

function initComposer() {
    composer0 = new EffectComposer(renderer);
}

function initFXAA() {
    const renderPass = new RenderPass(scene, camera);
    const FXAAShaderPass = new ShaderPass(FXAAShader)
    const pixelRatio = renderer.getPixelRatio()
    FXAAShaderPass.material.uniforms['resolution'].value.x = 1 / (window.innerWidth * pixelRatio)
    FXAAShaderPass.material.uniforms['resolution'].value.y = 1 / (window.innerHeight * pixelRatio)
    composer0.addPass(renderPass)
    composer0.addPass(FXAAShaderPass)
}

function initSkybox() {
    scene.background = new THREE.CubeTextureLoader()
        .setPath('./images/skybox/')
        .load([
            '远山_RT.jpg',
            '远山_LF.jpg',
            '远山_UP.jpg',
            '远山_DN.jpg',
            '远山_BK.jpg',
            '远山_FR.jpg'
        ]);
}

function initControls() {
    controls = new OrbitControls(camera, renderer.domElement)
    controls.enableZoom = true
    controls.minDistance = 40
    controls.maxDistance = 500
    controls.enablePan = true
    controls.target.set(0, 0, 0)
}

function initGui() {
    let options = new function () {
        this.batchNo = '';
        this.qty = 0;
        this.qtyUom = '';
        this.qty2 = 0;
        this.实时全景监控 = function () {
            window.open("3DVideo.html");
        };
    };
    let gui = new dat.GUI();
    gui.domElement.style = 'position:absolute;top:10px;right:0px;height:600px';
    gui.add(options, 'batchNo').name("物料批号：").listen();
    gui.add(options, 'qty').name("数量：").listen();
    gui.add(options, 'qtyUom').name("单位：").listen();
    gui.add(options, 'qty2').name("件数：").listen();
    gui.add(options, '实时全景监控');
}

function initEcharts() {
    let pieChart = echarts.init($("<canvas width='512' height='512'></canvas>")[0]);
    const option = {
        color: ['#3398DB'],
        tooltip: {
            trigger: 'axis',
            axisPointer: {
                type: 'shadow'
            }
        },
        grid: {
            left: '3%',
            right: '4%',
            bottom: '3%',
            containLabel: true
        },
        xAxis: [
            {
                type: 'category',
                data: ['Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat', 'Sun'],
                axisTick: {
                    alignWithLabel: true
                }
            }
        ],
        yAxis: [
            {
                type: 'value'
            }
        ],
        series: [
            {
                name: '直接访问',
                type: 'bar',
                barWidth: '60%',
                data: [10, 52, 200, 334, 390, 330, 220]
            }
        ]
    };
    pieChart.setOption(option);

    pieChart.on('finished', function () {
        const infoEchart = new THREE.TextureLoader().load(pieChart.getDataURL());

        const infoEchartMaterial = new THREE.MeshBasicMaterial({
            transparent: true,
            map: infoEchart,
            side: THREE.DoubleSide
        });

        let echartPlane = new THREE.Mesh(new THREE.PlaneGeometry(100, 100), infoEchartMaterial);
        echartPlane.position.set(100, 150, 0);
        scene.add(echartPlane);

    });

    let pieChart2 = echarts.init($("<canvas width='512' height='512'></canvas>")[0]);
    const option2 = {
        title: {
            text: '车辆访问来源',
            subtext: '纯属虚构',
            x: 'center'
        },
        tooltip: {
            trigger: 'item',
            formatter: "{a} <br/>{b} : {c} ({d}%)"
        },
        legend: {
            orient: 'vertical',
            left: 'left',
            data: ['第一车道', '第二车道', '第三车道', '第四车道', '第五车道']
        },
        series: [
            {
                name: '访问来源',
                type: 'pie',
                radius: '55%',
                center: ['50%', '60%'],
                data: [
                    {value: 335, name: '第一车道'},
                    {value: 310, name: '第二车道'},
                    {value: 234, name: '第三车道'},
                    {value: 135, name: '第四车道'},
                    {value: 1548, name: '第五车道'}
                ],
                itemStyle: {
                    emphasis: {
                        shadowBlur: 10,
                        shadowOffsetX: 0,
                        shadowColor: 'rgba(0, 0, 0, 0.5)'
                    }
                }
            }
        ]
    };
    pieChart2.setOption(option2);

    pieChart2.on('finished', function () {
        const spriteMap = new THREE.TextureLoader().load(pieChart2.getDataURL());

        const spriteMaterial = new THREE.SpriteMaterial({
            transparent: true,
            map: spriteMap,
            side: THREE.DoubleSide
        });

        let sprite = new THREE.Sprite(spriteMaterial);
        sprite.scale.set(150, 150, 1)
        sprite.position.set(-100, 180, 0);
        scene.add(sprite);
    });
}

function createFloor() {
    let loader = new THREE.TextureLoader();
    loader.load("./images/floor.jpg", function (texture) {
        texture.wrapS = texture.wrapT = THREE.RepeatWrapping;
        texture.repeat.set(10, 10);
        let floorGeometry = new THREE.BoxGeometry(1800, 700, 1);
        let floorMaterial = new THREE.MeshBasicMaterial({
            map: texture,
        });
        let floor = new THREE.Mesh(floorGeometry, floorMaterial);
        floor.rotation.x = -Math.PI / 2;
        floor.name = "地面";
        scene.add(floor);
    });
}

function addVideoPlane(x, y, z, width, length, scene, videoId) {
    const planeGeometry = new THREE.PlaneGeometry(width, length);
    let material = new THREE.MeshPhongMaterial();
    material.side = THREE.DoubleSide;
    const video = document.getElementById(videoId);
    let texture = new THREE.VideoTexture(video);
    texture.minFilter = THREE.LinearFilter;
    texture.magFilter = THREE.LinearFilter;
    texture.format = THREE.RGBFormat;
    material.map = texture;
    let mesh = new THREE.Mesh(planeGeometry, material);
    mesh.position.set(x, y, z);
    scene.add(mesh);
}

function addArea(x, z, width, length, scene, name, textColor, font_size, textposition) {
    addPlane(x, z, width, length, scene);

    new THREE.FontLoader().load('./FZYaoTi_Regular.json', function (font) {
        ////加入立体文字
        let text = new THREE.TextGeometry(name.split("$")[1], {
            // 设定文字字体
            font: font,
            //尺寸
            size: font_size,
            //厚度
            height: 0.01
        });
        text.computeBoundingBox();
        //3D文字材质
        const m = new THREE.MeshStandardMaterial({color: "#" + textColor});
        let mesh = new THREE.Mesh(text, m);
        if (textposition == "左对齐") {
            mesh.position.x = x - width / 2 + 10;
        } else if (textposition == "居中") {
            mesh.position.x = x - 15;
        } else if (textposition == "右对齐") {
            mesh.position.x = x + width / 2 - 60;
        };
        mesh.position.y = 1.3;
        mesh.position.z = z + length / 2 - 100;
        mesh.rotation.x = -Math.PI / 2.0;
        scene.add(mesh);
    });
}

function addPlane(x, z, width, length, scene) {
    let LineMat = new THREE.MeshLambertMaterial();
    const lineWidth = 2;
    const geometry = new THREE.PlaneGeometry(lineWidth, length);
    let obj = new THREE.Mesh(geometry, LineMat);
    obj.position.set(x, 1.5, z);
    obj.rotation.x = -Math.PI / 2.0;
    let obj2 = obj.clone();
    obj2.translateX(width);

    const geometry2 = new THREE.PlaneGeometry(lineWidth, width);
    let obj3 = new THREE.Mesh(geometry2, LineMat);
    obj3.position.set(x + width / 2, 1.5, z - length / 2 + lineWidth / 2);
    obj3.rotation.x = -Math.PI / 2.0;
    obj3.rotation.z = -Math.PI / 2.0;
    let obj4 = obj3.clone();
    obj4.translateX(length - lineWidth);

    let group = new THREE.Group();
    group.add(obj);
    group.add(obj2);
    group.add(obj3);
    group.add(obj4);
    group.translateX(-width / 2);
    scene.add(group);
}

function initBuild(path, name, sx, sy, sz, px, py, pz, rx, ry, rz) {
    mtlLoader = new MTLLoader();
    mtlLoader.setPath(path);
    mtlLoader.load(name + '.mtl', materials => {
        materials.preload();
        objLoader = new OBJLoader();
        objLoader.setPath(path);
        objLoader.setMaterials(materials);
        objLoader.load(name + '.obj', object => {
            object.traverse(e => {
                if (e.material) {
                    if (Array.isArray(e.material)) {
                        e.material.forEach(m => {
                            m.opacity = 1;
                        })
                    } else {
                        e.material.opacity = 1;
                    }
                }
            });
            object.name = name;
            object.rotation.x = rx;
            object.rotation.y = ry;
            object.rotation.z = rz;
            object.scale.set(sx, sy, sz);
            object.position.x = px;
            object.position.y = py;
            object.position.z = pz;
            scene.add(object);
            objects.push(object);
        }, xhr => {
            console.log((xhr.loaded / xhr.total * 100) + '% loaded');
        }, error => {
            console.log(error);
        })
    })
}

function initContent() {
    Label1 = new SpriteText('安置地，留用地', 8);
    Label1.color = 'black';
    Label1.backgroundColor = 'rgba(255,255,255,0.9)';
    Label1.borderColor = 'black';
    Label1.borderWidth = 1.0;
    Label1.borderRadius = 3;
    Label1.position.x = -140;
    Label1.position.y = 80;
    Label1.position.z = -90;

    Label2 = new SpriteText('接驳巴士站', 8);
    Label2.color = 'black';
    Label2.backgroundColor = 'rgba(255,255,255,0.9)';
    Label2.borderColor = 'black';
    Label2.borderWidth = 1.0;
    Label2.borderRadius = 3;
    Label2.position.x = -210;
    Label2.position.y = 80;
    Label2.position.z = 120;
}

function onWindowResize() {
    camera.aspect = window.innerWidth / window.innerHeight;
    camera.updateProjectionMatrix()
    renderer.setSize(window.innerWidth, window.innerHeight);
}

function onMouseClick(event) {
    mouse.x = (event.clientX / window.innerWidth) * 2 - 1;
    mouse.y = -(event.clientY / window.innerHeight) * 2 + 1;

    raycaster.setFromCamera(mouse, camera);

    intersects = raycaster.intersectObjects(objects, true);

    if (intersects.length > 0) {
        scene.remove(Label);
        let obj = intersects[0].object.parent;
        if(obj.name === '小区'){
            Label = Label1;
        } else {
            Label = Label2;
        }
        scene.add(Label);
    } else {
        scene.remove(Label);
    }

    animate();
}

function initStats() {
    let stats = new Stats();
    stats.domElement.style.position = 'absolute';
    stats.domElement.style.left = '0px';
    stats.domElement.style.top = '0px';
    document.body.appendChild(stats.domElement);
    return stats;
}s

function update() {
    stats.update();
}

function animate() {
    requestAnimationFrame(animate);
    composer0.render();
    update();
}