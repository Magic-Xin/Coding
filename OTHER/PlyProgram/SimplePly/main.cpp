#include <iostream>
#include <cstring>
#include <sstream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef struct{
    float x, y, z;
}
float3;

template <class Type>
Type stringToNum(const string& str)
{
    istringstream iss(str);
    Type num;
    iss >> num;
    return num;
}

void split(float* data, char* str, const char* delim){
    if(str == NULL) return;
    char *p = strtok(str, delim);
    if(p) {
        for (int i = 0; i < 3; i++) {
            string s = p;
            data[i] = stringToNum<float>(s);
            p = strtok(NULL, delim);
        }
    }
}

vector<float3> read_ply(const char* filePath, int &num){
    vector<float3> vertices;

    FILE* file = fopen(filePath, "r");
    if (file == NULL) {
        cout << "error" << endl;
        exit(0);
    }
    float data[3];
    char lines[100];
    bool begin = false;

    clock_t start, end;
    start = clock();
    while(fgets(lines, 100, file) != NULL){
        char* line = lines;
        if(!begin){
            string content = line;
            if(content.find("end_header") != string::npos){
                begin = true;
                continue;
            }
            if(content.find("element vertex") != string::npos){
                split(data, line, " ");
                num = (int) data[2];
            }
        }
        else{
            split(data, line, " ");
            float3 vertex;
            vertex.x = data[0];
            vertex.y = data[1];
            vertex.z = data[2];
            vertices.push_back(vertex);
        }
    }
    end = clock();
    cout << "Read finished in: " << (double)(end - start)/CLOCKS_PER_SEC  << "s" << endl;
    fclose(file);
    return vertices;
}

int main() {
    int num;
    vector<float3> vertices = read_ply("c0000.ply", num);
    cout << "Elements vertices :" << num << endl;
    cout << "Vertices vector size: " << vertices.size() << endl;
    cout << "The last vertex data: " << vertices.back().x << " " << vertices.back().y << " " << vertices.back().z << endl;
    return 0;
}
