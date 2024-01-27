#include"total.h"
#include<chrono>
#include <map>
void InitQueue(LinkQueue& Q) {
    Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
    Q.front->next = NULL;
    Q.rear->next = NULL;
}
void EnQueue(LinkQueue& Q, SqList e) {
    QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
    p->S = e;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
}
void Dequeue(LinkQueue& Q, SqList& e) {
    if (Q.front == Q.rear) printf("空队列");
    QueuePtr p = Q.front->next;
    e = p->S;
    Q.front->next = p->next;
    if (p == Q.rear) Q.rear = Q.front;
    free(p);
}
bool iskong(LinkQueue Q) {
    if (Q.front == Q.rear)
        return true;
    else return false;
}
void DeepCopySqList(const SqList& src, SqList& dest) {
    dest.length = src.length;  // 复制长度信息

    dest.T = new RedType[src.length];  // 为目标T分配新的内存空间

    for (int i = 0; i < src.length; i++) {
        dest.T[i] = src.T[i];  // 逐个复制RedType的内容
    }
}


void generateRandomData(const char* filename, int num)
{
    ofstream outFile(filename);
    if (outFile.is_open())
    {
        srand(time(NULL));
        for (int i = 0; i < num; ++i)
        {
            int val = rand() % 1000;
            outFile << val << endl;
        }
        outFile.close();
    }
    else {
        std::cout << "无法打开或创建文件！" << std::endl;
    }


}


void readDataFromFile(const char* filename, SqList& s)
{
    ifstream inFile(filename);
    if (inFile.is_open())
    {
        for (int i = 1; i < s.length; i++)
        {
            inFile >> s.T[i].key; // 从文件中读取每个随机数并存储到数组中
        }

        inFile.close(); // 关闭文件
    }
    else {
        std::cout << "无法打开文件！" << std::endl;
    }

    inFile.close();
}
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}
int main() {
    map<double, string> numToString;
    map<int, string>T1;
    map<int, string>T2;
    srand(time(0)); 
    static int i = 0;
    SqList Q1, Q2, Q3, Q4, Q5, Q6, Q7, Q8, Q9, Q10;
    Q1.T = new RedType[2000000];
    Q2.T = new RedType[2000000];
    Q3.T = new RedType[2000000];
    Q4.T = new RedType[2000000];
    Q5.T = new RedType[2000000];
    Q6.T = new RedType[2000000];
    Q7.T = new RedType[2000000];
    Q8.T = new RedType[2000000];
    Q9.T = new RedType[2000000];
    Q10.T = new RedType[2000000];
    SqList N1, N2, N3;
    N1.length = 1001;
    N2.length = 10001;
    N3.length = 100001;
    N1.T = new RedType[2000000];
    N2.T = new RedType[2000000];
    N3.T = new RedType[2000000];
    int t1[100];
    int t2[100];
    static int a = 0;
    static int b = 0;
    string s = "yes";
    cout << "请选择随机生成数据还是文件内的数据（1/2):";
    int flag = 0;
    cin >> flag;
    if (flag == 1) {
        Q1.length = Q2.length = Q3.length = Q4.length = Q5.length = Q6.length = Q7.length = Q8.length = Q9.length = Q10.length = 501;
        for (int j = 0; j < 500; j++) {
            Q1.T[j + 1].key = rand() % 1000;
            Q2.T[j + 1].key = rand() % 1000;
            Q3.T[j + 1].key = rand() % 1000;
            Q4.T[j + 1].key = rand() % 1000;
            Q5.T[j + 1].key = rand() % 1000;
            Q6.T[j + 1].key = rand() % 1000;
            Q7.T[j + 1].key = rand() % 1000;
            Q8.T[j + 1].key = rand() % 1000;
            Q9.T[j + 1].key = rand() % 1000;
            Q10.T[j + 1].key = rand() % 1000;
        }



        int compareCount = 0;
        int moveCount = 0;

        LinkQueue Q;
        InitQueue(Q);
        //    cout << 666;
        EnQueue(Q, Q1);

        EnQueue(Q, Q2);
        EnQueue(Q, Q3);
        EnQueue(Q, Q4);
        EnQueue(Q, Q5);
        EnQueue(Q, Q6);
        EnQueue(Q, Q7);
        EnQueue(Q, Q8);
        EnQueue(Q, Q9);
        EnQueue(Q, Q10);
        cout << "<1代表折半插入排序,2代表快速排序,3代表冒泡排序,4代表堆排序,5代表基数排序>"<<endl;
        while (s == "yes") {
            SqList M;
            Dequeue(Q, M);
            int choice;
            cout << "请输入1/2/3/4/5来选择想要使用的排序方法:";
            cin >> choice;
            switch (choice) {
            case 1:
                cout << "折半插入排序结果如下:" << endl;
                BinsertSort(M, compareCount, moveCount);
                for (int t = 1; t <= 500; t++) {
                    cout << M.T[t].key << " ";
                    if (t % 10 == 0) cout << endl;
                }
                t1[a] = compareCount;
                T1[t1[a]] = "折半插入排序";
                    a++;
                t2[b] = moveCount;
                T2[t2[b]] = "折半插入排序";
                    b++;
                break;
            case 2:
                cout << "快速排序结果如下:" << endl;
                Qsort(M, 1, M.length - 1, compareCount, moveCount);
                for (int t = 1; t <= 500; t++) {
                    cout << M.T[t].key << " ";
                    if (t % 10 == 0) cout << endl;
                }
                t1[a] = compareCount;
                T1[t1[a]] = "快速排序";
                a++;
                t2[b] = moveCount;
                T2[t2[b]] = "快速排序";
                b++;
                break;
            case 3:
                cout << "冒泡排序结果如下:" << endl;
                bubblesort(M, compareCount, moveCount);
                for (int t = 1; t <= 500; t++) {
                    cout << M.T[t].key << " ";
                    if (t % 10 == 0) cout << endl;
                }
                t1[a] = compareCount;
                T1[t1[a]] = "冒泡排序";
                a++;
                t2[b] = moveCount;
                T2[t2[b]] = "冒泡排序";
                b++;
                break;
            case 4:
                cout << "堆排序结果如下:" << endl;
                HeapSort(M, M.length - 1, compareCount, moveCount);
                for (int t = 1; t <= 500; t++) {
                    cout << M.T[t].key << " ";
                    if (t % 10 == 0) cout << endl;
                }
                t1[a] = compareCount;
                T1[t1[a]] = "堆排序";
                a++;
                t2[b] = moveCount;
                T2[t2[b]] = "堆排序";
                b++;
                break;
            case 5:
                cout << "基数排序结果如下:" << endl;
                radixsort(M, M.length, compareCount, moveCount);
                for (int t = 1; t <= 500; t++) {
                    cout << M.T[t].key << " ";
                    if (t % 10 == 0) cout << endl;
                }
                t1[a] = compareCount;
                T1[t1[a]] = "基数排序";
                a++;
                t2[b] = moveCount;
                T2[t2[b]] = "基数排序";
                b++;
                break;
            }

            cout << "Group " << ++i << ":" << endl;
            cout << "Compare Count: " << compareCount << endl;
            cout << "Move Count: " << moveCount << endl;
            cout << endl;
            compareCount = 0;
            moveCount = 0;
            cout << "是否想要继续排序(yes/no)(不可超过十次):";
            cin >> s;
        }
        selectionSort(t1, a);
        selectionSort(t2, b);
        cout << "对于当前随机整数排序算法按'比较次数'好坏如下:";
        for (int i = 0; i < a; i++) {
            cout << T1[t1[i]] << " ";
        }
        cout << endl;
        cout << "对于当前随机整数排序算法按'移动次数'好坏如下:";
        for (int i = 0; i < b; i++) {
            cout << T2[t2[i]] << " ";
        }
        cout << endl;
        system("pause");
    }
    else {
        static int f = 1;
        const char* filename1 = "E:\\数据结构\\data1.txt";
        generateRandomData(filename1, 1000);
        const char* filename2 = "E:\\数据结构\\data2.txt";
        generateRandomData(filename2, 10000);
        const char* filename3 = "E:\\数据结构\\data3.txt";
        generateRandomData(filename3, 100000);
        readDataFromFile(filename1, N1);
        readDataFromFile(filename2, N2);
        readDataFromFile(filename3, N3);
        LinkQueue Q;
        InitQueue(Q);
        EnQueue(Q, N1);
        EnQueue(Q, N2);
        EnQueue(Q, N3);
        int compareCount = 0;
        int moveCount = 0;
       
        while (s == "yes"&& !iskong(Q)) {
            cout << endl;
            cout << "第" << f << "个文件排序结果统计:" << endl;
            SqList M;
            SqList M1;
            Dequeue(Q, M);
            DeepCopySqList(M, M1);
            auto start = std::chrono::steady_clock::now();
            auto end = std::chrono::steady_clock::now();
            std::chrono::duration<double> elapsed_seconds = end - start;
            
            


                cout << "1)折半插入排序测试结果如下:" << endl;
                start = std::chrono::steady_clock::now();
                BinsertSort(M, compareCount, moveCount);
                end = std::chrono::steady_clock::now();
                elapsed_seconds = end - start;
                std::cout << "折半插入排序运行时间：" << elapsed_seconds.count() << " 秒" << std::endl;
             //   M.t1 = std::chrono::duration_cast<std::chrono::duration<double>>(elapsed_seconds);
             //   numToString[static_cast<double>(M.t1.count())] = "折半插入排序";
                M.t1 = elapsed_seconds.count();
                numToString[M.t1] = "折半插入排序";
             DeepCopySqList(M1, M);
          
                cout << "2)快速排序测试结果如下:" << endl;
               
                start = std::chrono::steady_clock::now();
                Qsort(M, 1, M.length - 1, compareCount, moveCount);
                end = std::chrono::steady_clock::now();
                elapsed_seconds = end - start;
                std::cout << "快速排序运行时间：" << elapsed_seconds.count() << " 秒" << std::endl;
                M.t2 = elapsed_seconds.count();
               
                numToString[M.t2] = "快速排序";
                DeepCopySqList(M1, M);
                cout << "3)冒泡排序测试结果如下:" << endl;
                
                start = std::chrono::steady_clock::now();
                bubblesort(M, compareCount, moveCount);
                end = std::chrono::steady_clock::now();
                elapsed_seconds = end - start;
                std::cout << "冒泡排序运行时间：" << elapsed_seconds.count() << " 秒" << std::endl;
                M.t3 = elapsed_seconds.count();
          
                numToString[M.t3] = "冒泡排序";
                DeepCopySqList(M1, M);
                cout << "4)堆排序测试结果如下:" << endl;
                start = std::chrono::steady_clock::now();
                HeapSort(M, M.length - 1, compareCount, moveCount);
                end = std::chrono::steady_clock::now();
                elapsed_seconds = end - start;
                std::cout << "堆排序运行时间：" << elapsed_seconds.count() << " 秒" << std::endl;
           
                M.t4 = elapsed_seconds.count();
                numToString[M.t4] = "堆排序";
                DeepCopySqList(M1, M);
             
                cout << "5)基数排序测试结果如下:" << endl;
                start = std::chrono::steady_clock::now();
                radixsort(M, M.length, compareCount, moveCount);
                end = std::chrono::steady_clock::now();
                elapsed_seconds = end - start;
                std::cout << "基数排序运行时间：" << elapsed_seconds.count() << " 秒" << std::endl;
                M.t5 = elapsed_seconds.count();
                numToString[M.t5] = "基数排序";
             
                f++;
               
                double record[5] = { M.t1, M.t2, M.t3, M.t4, M.t5 };
                for (int i = 0; i < 4; i++) {
                    int minIndex = i;
                    for (int j = i + 1; j < 5; j++) {
                        if (record[j] < record[minIndex]) {
                            minIndex = j;
                        }
                    }
                    if (minIndex != i) {
                      
                        double temp = record[i];
                        record[i] = record[minIndex];
                        record[minIndex] = temp;
                    //    string tempName = numToString[record[i]];
                    //    numToString[record[i]] = numToString[record[minIndex]];
                    //    numToString[record[minIndex]] = tempName;
                    }
                }
           //     cout << record[2]<<endl;
           //     cout << numToString[record[2]]<<endl;
                cout << "对于当前测试文件排序算法好坏依次为:";
                for (int i = 0; i < 5; i++) {
                    cout << numToString[record[i]]<<" ";
                }
                cout << endl;
            }
            
        system("pause");
        }
       
    delete[]Q1.T;
    delete[]Q2.T;
    delete[]Q3.T;
    delete[]Q4.T;
    delete[]Q5.T;
    delete[]Q6.T;
    delete[]Q7.T;
    delete[]Q8.T;
    delete[]Q9.T;
    delete[]Q10.T;
    delete[]N1.T;
    delete[]N2.T;
    delete[]N3.T;
    return 0;
}
