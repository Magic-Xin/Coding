#include<iostream>
using namespace std;
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<fstream>
#define num 1000
typedef struct//哈夫曼树的结构体
{
    char ch;
    int weight;//权值
    int parent,lchild,rchild;
}HTNode,*HuffmanTree;
typedef char **HuffmanCode;
void Select(HuffmanTree &HT,int a,int *p1,int *p2)
//Select函数，选出HT树到a为止，权值最小且parent为0的2个节点
{
    int i,j,x,y,count,temp;
    for(j=1,count=1;j<=a;j++)
    {
        if(HT[j].parent==0)
        {
            if(count==1)
                x=j;
            if(count==2)
                y=j;
            count++;            
        }
        if(count>2)
            break;
    }

    if(HT[x].weight>HT[y].weight)//令x结点权值小于y结点权值
    {
        temp=y;
        y=x;
        x=temp;
    }
    i=(x>y?x:y)+1;
    while(i<=a)
    {
        if(HT[i].parent==0)
        {
            if(HT[i].weight<HT[x].weight)
            {
                y=x;
                x=i;
            }
            else
            {
                if(HT[i].weight>=HT[x].weight&&HT[i].weight<HT[y].weight)
                    y=i;
            }
        }
        i++;
    }
    *p1=HT[x].weight<=HT[y].weight?x:y;
    *p2=HT[x].weight>HT[y].weight?x:y;


}
void HuffmanCoding(HuffmanTree &HT,HuffmanCode &HC,int n)//构建赫夫曼树HT，并求出n个字符的赫夫曼编码HC
{
    int i,start,c,f,m,w;
    int p1,p2;
    char *cd,z;
    if(n<=1)
        exit(1);
    m=2*n-1;//n个叶子结点的哈夫曼树共有2n-1个结点
    HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode));//0号单元未使用
    for(i=1;i<=n;i++)//初始化n个叶子结点
    {
        printf("请输入第%d字符信息和权值：",i);
        scanf("%c%d",&z,&w);
        while(getchar()!='\n')
        {
            continue;
        }
        HT[i].ch=z;
        HT[i].weight=w;
        HT[i].parent=0;
        HT[i].lchild=0;
        HT[i].rchild=0;
    }
    for(i=n+1;i<=m;i++)//初始化其余结点
    {
        HT[i].ch='0';
        HT[i].weight=0;
        HT[i].parent=0;
        HT[i].lchild=0;
        HT[i].rchild=0;
    }
    for(i=n+1;i<=m;i++)//建立哈夫曼树
    {
        Select(HT,i-1,&p1,&p2);
        HT[p1].parent=i;HT[p2].parent=i;
        HT[i].lchild=p1;HT[i].rchild=p2;
        HT[i].weight=HT[p1].weight+HT[p2].weight;
    }
    //从叶子到根逆向求每个字符的哈夫曼编码
    HC=(HuffmanCode)malloc((n+1)*sizeof(char *));
    cd=(char *)malloc(n*sizeof(char));
    cd[n-1]='\0';
    for(i=1;i<=n;i++)
    {
        start =n-1;
        for(c=i,f=HT[i].parent;f!=0;c=f,f=HT[f].parent)
        {
            if(HT[f].lchild==c)
                cd[--start]='0';
            else
                cd[--start]='1';
        }
        HC[i]=(char *)malloc((n-start)*sizeof(char));
        strcpy(HC[i],&cd[start]);
    }
    free(cd);
}
int main()
{
    char code[100],h[100],hl[100];
    int n,i,j,k,l;
    ifstream input_file; 
    ofstream output_file;
    FILE *fp1,*fp2,*fp3,*fp4,*fp5;
    char choice,str[100];
    HuffmanTree HT;
    HuffmanCode HC;
    cout<<"            哈夫曼编码器\n";
    while(choice!='Q'&&choice!='q')            //当choice的值不为q且不为Q时循环
    {
    
        cout<<"功能: "<<"I(初始化)"<<""<<"E(编码)"<<""<<"D(译码)"<<""<<"P(打印)"<<""<<"Q(退出)\n";
        cout<<"请输入您要选择的功能：";
        cin>>choice;
        if(choice=='I'||choice=='i')              //初始化赫夫曼树
        {
            cout<<"请输入字符个数：";
            cin>>n;
            HuffmanCoding(HT,HC,n);
            for(i=1;i<=n;++i)
            {
                cout<<HT[i].ch<<":"<<HC[i]<<endl;
                
            }
            fp1=fopen("hfmTree.txt","w");
            for(i=1;i<=n;++i)
            {
                fprintf(fp1,"(%c %s)\n",HT[i].ch,HC[i]);

            }
          fclose(fp1);
            cout<<"赫夫曼树已经创建完毕，并且已经放入hfmTree.txt文件中!"<<endl;
        }
        else if(choice=='E'||choice=='e')           //进行编码，并将字符放入ToBeTran.txt，码值放入CodeFile.txt中
        {
            printf("请输入字符：");
            gets(str);
            fp2=fopen("ToBeTran.txt","w");
            fprintf(fp2,"%s",str);
            fclose(fp2);
            fp3=fopen("CodeFile.txt","w");
            for(i=0;i<strlen(str);i++){
                for(j=1;j<=n;++j)
                {
                    if(HT[j].ch==str[i])
                    {
                        fprintf(fp3,"%s",HC[j]);
                        break;
                    }
                }
            }
            fclose(fp3);
            cout<<"\n";
            fp4=fopen("CodeFile.txt","r"); 
            char H1;//从CodeFile.txt中读入编码，输出在终端
            cout<<"编码值为：\n";
            while(!feof(fp4))
            {
                H1=fgetc(fp4);
                cout<<H1;
            }
            fclose(fp4);
            cout<<"\n编码完毕，并且已经存入CodeFile.txt文件！\n";
        }
       else if(choice=='D'||choice=='d')     //读入CodeFile.txt中的编码进行译码，将译出来的字符放入Textfile.txt中
        {
            input_file.open("CodeFile.txt");
            if(!input_file){
                cout<<"can't open file!"<<endl;
                return 1;
            }
            input_file>>h;
            input_file.close();
            output_file.open("Textfile.txt");
            if(!output_file)
            {
                cout<<"can't open file!"<<endl;
                return 1;
            }
            k=0;
            while(h[k]!='\0')           //先用编码中的前几个和字符的编码相比较，然后往后移
            {
                for(i=1;i<=n;i++){
                    l=k;
                    for(j=0;j<strlen(HC[i]);j++,l++)
                    {
                        hl[j]=h[l];
                    }
                    hl[j]='\0';
                    if(strcmp(HC[i],hl)==0)
                    {
                        output_file<<HT[i].ch;
                        k=k+strlen(HC[i]);
                        break;
                    }
                }
            }
            output_file.close();
            input_file.open("Textfile.txt");

            if(!input_file){
                cout<<"can't open file!"<<endl;
                return 1;
            }
        //    input_file>>h;
            input_file.getline(h,100);//获取文件里的一行
            cout<<"译码结果为：";
           printf("%s\n",h);
            input_file.close();
            cout<<"译码结果已存入Textfile.txt中\n";
        }
       else if(choice=='P'||choice=='p')//每行50个代码
        {
            char a[num];
            fp4=fopen("CodeFile.txt","r"); 
            fgets(a,num,fp4);
            cout<<"打印代码文件:"<<endl;
            int l=strlen(a);
            for(int j=0;j<l;j++)
            {
                cout<<a[j];
                if((j+1)%50==0)
                    cout<<endl;
            }
            fclose(fp4);
            fp5=fopen("CodePrint.txt","w");
            for(int k=0;k<l;k++)
            {
                fprintf(fp5,"%c",a[k]);
                if((k+1)%50==0)
                {
                    fprintf(fp5,"\n");
                }
            }
            cout<<"\n该字符形式已存入CodePrint.txt中\n";
            fclose(fp5);
        }
        else if(choice=='Q'||choice=='q')            //退出程序
        { 
            exit(0);
        }
        
        else               //如果选了选项之外的就让用户重新选择
        {
            cout<<"您没有输入正确的步骤，请重新输入！"<<endl;
        }
        cout<<endl;
    }
    return 0;
}