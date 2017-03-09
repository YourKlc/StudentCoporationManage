#include<iostream>
#define _WIN32_WINNT    0x0500
#include<conio.h>
#include<windows.h>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define MALE 1
#define FEMALE 2
#define LL long long
using namespace std;
#include "student.h"

vector<student > stu;
#include "top.h"
#include "corporation.h"

vector<Corporation > C;

void Printstin(struct student s)//打印学生信息
{
    pt();
    // printf("201522332\tklc\tnan\tgrade1\tcomputerscience\n");//学号\t姓名\t性别\t年级\t专业
    printf("%-10I64d\t%s\t",s.num,s.name);
    if(s.sex==FEMALE) printf("女");
    else if(s.sex==MALE) printf("男");
    else printf("未知性别");
    printf("\t%d年级\t%s\n",s.grade,s.major);
    /**找到包含此学生的社团,并保存到string S中**/
    vector<string > w;
    vector<int > e;
    w.clear();
    e.clear();
    int i,j,d=C.size(),p;
    for(i=0; i<d; i++)
    {
        p=C[i].studen.size();
        for(j=0; j<p; j++)
        {
            if(C[i].studen[j]==s.num)
            {
                w.push_back(C[i].name);
                e.push_back(C[i].num);
                break;
            }
        }
    }
    p=w.size();
    if(p!=0)
    {
        pt();
        puts("已加入的社团:");
        pt();
        j=0;
        for(i=0; i<p; i++)
        {
            if(j==5)
            {
                puts("");
                pt();
                j=0;
            }
            cout<<w[i]<<"("<<e[i]<<")   ";
        }
    }
    printf("\n");
}
int Addstudent(struct student &tep)//添加学生
{
    pt();
    puts("■添加新学生:");
    //int et=0;
    char c;
    char ss[100];
    while(1)
    {
        pt();
        printf("■输入学号:");
        gets(ss);
        int t=judge1(ss);
        if(t==-1)
        {
            tep.num=change(ss);
            while(1)
            {
                pt();
                printf("■输入姓名:");
                gets(ss);
                if(judge2(ss)==1)
                {
                    strcpy(tep.name,ss);
                    while(1)
                    {
                        pt();
                        printf("■输入一个数字代表性别:1为男,2为女:");
                        gets(ss);
                        if(judge3(ss)==1)
                        {
                            tep.sex=ss[0]-'0';
                            while(1)
                            {

                                pt();
                                printf("■输入年级(纯数字):");
                                gets(ss);
                                if(judge4(ss)==1)
                                {
                                    tep.grade=change(ss);
                                    while(1)
                                    {
                                        pt();
                                        printf("■输入专业:");
                                        gets(ss);
                                        if(judge2(ss)==1)
                                        {
                                            strcpy(tep.major,ss);
                                            system("cls");
                                            pt();
                                            puts("■请确认该学生信息:");
                                            tabs();
                                            Printstin(tep);
                                            pt();
                                            puts("■确认添加按Y,取消按N");
                                            c=getch();
                                            while(YNjudge(c)==0)
                                            {
                                                c=getch();
                                            }
                                            if(c=='Y'||c=='y')
                                            {
                                                //添加
                                                stu.push_back(tep);
                                                sort(stu.begin(),stu.end(),Cmp);
                                                pt();
                                                puts("■已成功添加");
                                            }
                                            else
                                            {
                                                pt();
                                                puts("■已取消添加");
                                            }
                                            return 1;
                                        }
                                        else
                                        {
                                            pt();
                                            printf("■专业格式错误,按Y重新输入,按N退出");
                                            c=getch();
                                            puts("");
                                            while(YNjudge(c)==0)
                                            {
                                                c=getch();
                                            }
                                            if(c=='N'||c=='n') return 0;
                                        }
                                    }
                                }
                                else
                                {
                                    pt();
                                    printf("■年级格式错误,按Y重新输入,按N退出");
                                    c=getch();
                                    puts("");
                                    while(YNjudge(c)==0)
                                    {
                                        c=getch();
                                    }
                                    if(c=='N'||c=='n') return 0;
                                }
                            }
                        }
                        else
                        {
                            pt();
                            printf("■性别格式错误,按Y重新输入,按N退出");
                            c=getch();
                            puts("");
                            while(YNjudge(c)==0)
                            {
                                c=getch();
                            }
                            if(c=='N'||c=='n') return 0;
                        }
                    }
                }
                else
                {
                    pt();
                    printf("■姓名格式错误,按Y重新输入,按N退出");
                    c=getch();
                    puts("");
                    while(YNjudge(c)==0)
                    {
                        c=getch();
                    }
                    if(c=='N'||c=='n') return 0;
                }
            }
        }
        else
        {
            pt();
            if(t==-2)
                printf("■学号格式错误,按Y重新输入,按N退出");
            else printf("■该学生已存在,按Y重新输入,按N退出");
            c=getch();
            puts("");
            while(YNjudge(c)==0)
            {
                c=getch();
            }
            if(c=='N'||c=='n') return 0;
        }
    }
}
bool ccmp(const Corporation &A,const Corporation &B)
{
    return A.num<B.num;
}

int Getstuname(long long num,char ss[])//得到学号为num的学生姓名并存到ss中,有返回1,无返回0
{
    int i,d=stu.size();
    for(i=0; i<d; i++)
        if(num==stu[i].num)
        {
            strcpy(ss,stu[i].name);
            return 1;
        }
    return 0;
}
int Findstuinc(long long num,int p)//在下标为p的社团中寻找学号为num的学生,有返回学生下标+1,无返回0
{
    int i,d=C[p].studen.size();
    for(i=0; i<d; i++)
        if(num==C[p].studen[i])
        {
            return i+1;
        }
    return 0;
}
/**找到包含此学生的社团,并删除该学生学号**/
void Del(long long s)
{
    int i,j,d=C.size(),p;
    for(i=0; i<d; i++)
    {
        p=C[i].studen.size();
        for(j=0; j<p; j++)
        {
            if(C[i].studen[j]==s)
            {
                if(C[i].huizhang==s)C[i].huizhang=0;
                if(C[i].mishu==s)C[i].mishu=0;
                C[i].studen.erase(C[i].studen.begin()+j);
                break;
            }
        }
    }
}
int judgec1(char m[])//社团编号合法性判断+判重 -2是格式不对,>=0是重合,-1是没有
{
    int d=strlen(m);
    if(d>6||d<=0) return -2;
    for(int i=0; i<d; i++)
    {
        if(m[i]<'0'||m[i]>'9') return -2;
    }
    int s=change(m);
    d=C.size();
    //printf("%d\n",d);
    for(int i=0; i<d; i++)
    {
        // printf("%lld %lld\n",stu[i].num,s);
        if(C[i].num==s) return i;
        if(C[i].num>s) break;
    }
    return -1;
}

int AddCor()//struct Corporation &c)//添加社团
{
    pt();
    puts("■添加新社团:");
    struct Corporation c;
    char m;
    char ss[100];
    while(1)
    {
        pt();
        printf("■输入社团编号:");
        gets(ss);
        int t=judgec1(ss);
        if(t==-1)
        {
            c.num=change(ss);
            while(1)
            {
                pt();
                printf("■输入社团名:");
                gets(ss);
                if(judge2(ss)==1)
                {
                    strcpy(c.name,ss);
                    while(1)
                    {
                        pt();
                        printf("■输入社团成立时间(注意:一旦确认无法更改,格式为XXXX-XX-XX):");
                        gets(ss);
                        if(judgec2(ss,c)==1)
                        {
                            system("cls");
                            pt();
                            puts("■请确认该社团信息:");
                            c.Show();
                            pt();
                            puts("■确认添加按Y,取消按N");
                            m=getch();
                            while(YNjudge(m)==0)
                            {
                                m=getch();
                            }
                            if(m=='Y'||m=='y')
                            {
                                //添加
                                C.push_back(c);
                                int d=C.size();
                                sort(C.begin(),C.end(),ccmp);
                                for(int i=0; i<d; i++)
                                    sort(C[i].studen.begin(),C[i].studen.end());
                                ///排序 ,社团编号排序及每个社团学生学号排序,
                                pt();
                                puts("■已成功添加");
                            }
                            else
                            {
                                pt();
                                puts("■已取消添加");
                            }
                            return 1;
                        }
                        else
                        {
                            pt();
                            printf("■社团日期格式错误,按Y重新输入,按N退出");
                            m=getch();
                            puts("");
                            while(YNjudge(m)==0)
                            {
                                m=getch();
                            }
                            if(m=='N'||m=='n') return 0;
                        }
                    }
                }
                else
                {
                    pt();
                    printf("■社团名格式错误,按Y重新输入,按N退出");
                    m=getch();
                    puts("");
                    while(YNjudge(m)==0)
                    {
                        m=getch();
                    }
                    if(m=='N'||m=='n') return 0;
                }
            }
        }
        else
        {
            pt();
            if(t==-2)
                printf("■编号格式错误,按Y重新输入,按N退出");
            else printf("■该社团已存在,按Y重新输入,按N退出");
            m=getch();
            puts("");
            while(YNjudge(m)==0)
            {
                m=getch();
            }
            if(m=='N'||m=='n') return 0;
        }
    }
}
int Delc()//删除社团
{
    char ss[100];
    while(1)
    {
        system("cls");
        pt();
        printf("■输入你要删除的社团编号:");
        gets(ss);
        int t=judgec1(ss);
        if(t>=0)
        {
            pt();
            puts("■确认要删除的社团信息:");
            C[t].Show();
            pt();
            printf("■是否删除?是按Y,否按N:");
            char m=getch();
            puts("");
            while(YNjudge(m)==0)
            {
                m=getch();
            }
            pt();
            if(m=='Y'||m=='y')
            {
                C.erase(C.begin()+t);
                puts("■成功删除!");
            }
            else puts("■取消删除");

            return 1;
        }
        else
        {
            pt();
            if(t==-2)
                printf("■编号格式错误,按Y重新输入,按N退出");
            else printf("■该社团不存在,按Y重新输入,按N退出");
            char m=getch();
            puts("");
            while(YNjudge(m)==0)
            {
                m=getch();
            }
            if(m=='N'||m=='n') return 0;
        }
    }
}
int Lookc()//查询详细信息
{
    char ss[100];
    char m;
    while(1)
    {
        system("cls");
        pt();
        printf("■输入你要查找的社团编号:");
        gets(ss);
        int t=judgec1(ss);
        if(t>=0)
        {
            C[t].Show2();
            puts("");
            pt();
            printf("■继续查找按Y,返回主菜单按N:");
            m=getch();
            puts("");
            while(YNjudge(m)==0)
            {
                m=getch();
            }
            if(m=='N'||m=='n') return 0;
        }
        else
        {
            pt();
            if(t==-2)
                printf("■编号格式错误,按Y重新输入,按N退出");
            else printf("■该社团不存在,按Y重新输入,按N退出");
            m=getch();
            puts("");
            while(YNjudge(m)==0)
            {
                m=getch();
            }
            if(m=='N'||m=='n') return 0;
        }
    }
}
void ShowAll()//显示所有社团简略信息
{
    puts("");
    tabc();
    int d=C.size();
    for(int i=0; i<d; i++)
        C[i].ShortShow();
}

void Setcor()//修改社团信息
{
    char ss[100],a;
    while(1)
    {
        system("cls");
        pt();
        printf("■修改社团信息:\n");
        pt();
        printf("■输入你要修改的社团编号:");
        gets(ss);
        int t=judgec1(ss);//t为社团编号
        if(t>=0)
        {
            pt();
            puts("■确认要修改的社团信息:");
            C[t].Show();
            pt();
            printf("■是否修改该社团?是按Y,否按N:");
            char m=getch();
            puts("");
            while(YNjudge(m)==0)
            {
                m=getch();
            }
            pt();
            if(m=='Y'||m=='y')
            {
                while(1)
                {
                    system("cls");
                    pt();
                    puts("■确认要修改的社团信息:");
                    C[t].Show();
                    tabc221();
                    a=getch();
                    while(a=='\b'||a==32)
                        a=getch();
                    if(a=='1')//修改社团名OK
                    {
                        puts("");
                        while(1)
                        {
                            pt();
                            printf("■输入要修改的社团名:");
                            gets(ss);
                            if(judge2(ss)==1)
                            {
                                pt();
                                printf("■修改之后的社团名为:%s,确定按Y,取消按N\n",ss);
                                a=getch();
                                while(YNjudge(a)==0)
                                    a=getch();
                                if(a=='Y'||a=='y')
                                {
                                    strcpy(C[t].name,ss);
                                    pt();
                                    puts("■修改成功!");
                                    system("pause");
                                }
                                break;
                            }
                            else
                            {
                                pt();
                                printf("■社团名格式不正确,重新输入按Y,退出按N");
                                a=getch();
                                puts("");
                                while(YNjudge(a)==0)
                                    a=getch();
                                if(a=='n'||a=='N')  break;
                            }
                        }
                    }
                    else if(a=='2')//修改会长
                    {
                        puts("");
                        while(1)
                        {
                            pt();
                            printf("■输入要修改的会长学号:");
                            gets(ss);
                            int tt=judge1(ss);//tt为学生下标
                            if(tt>=0)
                            {
                                int qt=Findstuinc(change(ss),t);
                                if(qt==1)
                                {
                                    pt();
                                    printf("■修改之后的会长学号为:%s,",ss);
                                    printf("■名字为%s,确定按Y,取消按N\n",stu[tt].name);
                                    a=getch();
                                    while(YNjudge(a)==0)
                                        a=getch();
                                    if(a=='Y'||a=='y')
                                    {
                                        C[t].huizhang=change(ss);
                                        pt();
                                        puts("■修改成功!");
                                        system("pause");
                                    }
                                    break;
                                }
                                else
                                {
                                    pt();
                                    printf("■该社团无此学生,按Y重新输入,按N退出");
                                    a=getch();
                                    puts("");
                                    while(YNjudge(a)==0)
                                        a=getch();
                                    if(a=='n'||a=='N')  break;
                                }

                            }
                            else
                            {
                                pt();
                                if(tt==-2)
                                    printf("■学号格式错误,按Y重新输入,按N退出");
                                else printf("■该学生未登记,按Y重新输入,按N退出");
                                a=getch();
                                puts("");
                                while(YNjudge(a)==0)
                                    a=getch();
                                if(a=='n'||a=='N')  break;
                            }
                        }
                    }
                    else if(a=='3')//修改秘书
                    {
                        puts("");
                        while(1)
                        {
                            pt();
                            printf("■输入要修改的秘书学号:");
                            gets(ss);
                            int tt=judge1(ss);//tt为学生下标
                            if(tt>=0)
                            {
                                int qt=Findstuinc(change(ss),t);
                                if(qt==1)
                                {
                                    pt();
                                    printf("■修改之后的秘书学号为:%s,",ss);
                                    printf("■名字为%s,确定按Y,取消按N\n",stu[tt].name);
                                    a=getch();
                                    while(YNjudge(a)==0)
                                        a=getch();
                                    if(a=='Y'||a=='y')
                                    {
                                        C[t].mishu=change(ss);
                                        pt();
                                        puts("■修改成功!");
                                        system("pause");
                                    }
                                    break;
                                }
                                else
                                {
                                    pt();
                                    printf("■该社团无此学生,按Y重新输入,按N退出");
                                    a=getch();
                                    puts("");
                                    while(YNjudge(a)==0)
                                        a=getch();
                                    if(a=='n'||a=='N')  break;
                                }

                            }
                            else
                            {
                                pt();
                                if(tt==-2)
                                    printf("■学号格式错误,按Y重新输入,按N退出");
                                else printf("■该学生未登记,按Y重新输入,按N退出");
                                a=getch();
                                puts("");
                                while(YNjudge(a)==0)
                                    a=getch();
                                if(a=='n'||a=='N')  break;
                            }
                        }

                    }
                    else return ;
                }
            }
            else puts("■取消修改");

            return ;
        }
        else
        {
            pt();
            if(t==-2)
                printf("■编号格式错误,按Y重新输入,按N退出");
            else printf("■该社团不存在,按Y重新输入,按N退出");
            char m=getch();
            puts("");
            while(YNjudge(m)==0)
            {
                m=getch();
            }
            if(m=='N'||m=='n') return ;
        }
    }

}

void Addstutocor(long long s)//加入社团,首先查找社团是否存在,查找社团里是否有该学生,s为学号
/********************************************************************************************************************************/
{
    char ss[100];
    puts("");
    while(1)
    {
        pt();
        printf("■输入要加入的社团编号:");
        gets(ss);
        int t=judgec1(ss);//t为社团编号
        if(t>=0)//若社团存在,检测学生是否在该社团中,如果不在,加入此社团,并sort该社团里的学生
        {
            int tt=Findstuinc(s,t);
            if(tt==0)
            {
                C[t].studen.push_back(s);
                C[t].Sort();
                pt();
                printf("■加入成功!");
                system("pause");
                break;
            }
            else
            {
                pt();
                printf("■该学生已在社团中,按Y重新输入,按N退出");
                char m=getch();
                puts("");
                while(YNjudge(m)==0)
                {
                    m=getch();
                }
                if(m=='N'||m=='n') return ;
            }
        }
        else
        {
            pt();
            if(t==-2)
                printf("■编号格式错误,按Y重新输入,按N退出");
            else printf("■该社团不存在,按Y重新输入,按N退出");
            char m=getch();
            puts("");
            while(YNjudge(m)==0)
            {
                m=getch();
            }
            if(m=='N'||m=='n') return ;
        }
    }
}
void Quitc(long long s)//退出社团,首先查找社团是否存在,查找社团里是否有该学生,s为学号
/********************************************************************************************************************************/
{
    char ss[100];
    puts("");
    while(1)
    {
        pt();
        printf("■输入要退出的社团编号:");
        gets(ss);
        int t=judgec1(ss);//t为社团编号
        if(t>=0)//若社团存在,检测学生是否在改社团中,如果不在,加入此社团,并sort该社团里的学生
        {
            int tt=Findstuinc(s,t);
            if(tt!=0)
            {
                C[t].studen.erase(C[t].studen.begin()+tt-1);
                pt();
                if(C[t].huizhang==s) C[t].huizhang=0;
                if(C[t].mishu==s) C[t].mishu=0;
                printf("■退出成功!");
                system("pause");
                break;
            }
            else
            {
                pt();
                printf("■该学生不在该社团中,按Y重新输入,按N退出");
                char m=getch();
                puts("");
                while(YNjudge(m)==0)
                {
                    m=getch();
                }
                if(m=='N'||m=='n') return ;
            }
        }
        else
        {
            pt();
            if(t==-2)
                printf("■编号格式错误,按Y重新输入,按N退出");
            else printf("■该社团不存在,按Y重新输入,按N退出");
            char m=getch();
            puts("");
            while(YNjudge(m)==0)
            {
                m=getch();
            }
            if(m=='N'||m=='n') return ;
        }
    }
}
void Setstuinc(LL s)//修改学生在社团中的信息
{
    char ss[100],a;
    puts("");
    while(1)
    {
        pt();
        printf("■输入要修改的社团编号:");
        gets(ss);
        int t=judgec1(ss);//t为社团编号
        if(t>=0)//若社团存在,检测学生是否在该社团中,
        {

            int tt=Findstuinc(s,t);
            if(tt!=0)//检测学生是否在该社团中, tt为下标+1
            {
                system("cls");
                tabs122();
                a=getch();
                if(a=='1'||a=='2'||a=='3')
                {
                    if(a=='1')
                    {
                        C[t].huizhang=s;
                    }
                    else if(a=='2')
                    {
                        C[t].mishu=s;
                    }
                    else
                    {
                        if(C[t].huizhang==s) C[t].huizhang=0;
                        if(C[t].mishu==s) C[t].mishu=0;
                    }
                    printf("■修改成功!");
                    system("pause");
                    return;
                }
                else break;

            }
            else
            {
                pt();
                printf("■该学生不在该社团中,按Y重新输入,按N退出");
                char m=getch();
                puts("");
                while(YNjudge(m)==0)
                {
                    m=getch();
                }
                if(m=='N'||m=='n') return ;
            }
        }
        else
        {
            pt();
            if(t==-2)
                printf("■社团编号格式错误,按Y重新输入,按N退出");
            else printf("■该社团不存在,按Y重新输入,按N退出");
            char m=getch();
            puts("");
            while(YNjudge(m)==0)
            {
                m=getch();
            }
            if(m=='N'||m=='n') return ;
        }
    }

}
bool cmp(const student &A,const student &B)
{
    return A.num<B.num;
}
/**main**/
int main()
{
    DeleteMenu(GetSystemMenu(GetConsoleWindow(), FALSE), SC_CLOSE, MF_BYCOMMAND);
    DrawMenuBar(GetConsoleWindow());//禁用关闭按钮

    //a为一个字符,i是个int变量,stu是存学生的数组
    //学号\t姓名\t性别\t年级\t专业
    //num name sex grade major
    //longlong string int int string


    struct student  tep;
    struct Corporation cc;

    char ss[100];//读输入信息;
    system("color f0");
    system("cls");
    system("mode con cols=130 lines=35");//宽 高

    int i;
    LL tepp;//初始学生数
    char datas[]="Student.txt";
    char datac[]="Corporation.txt";
    FILE *file1,*file2;
    if((file1=fopen(datas,"a+"))!=NULL)
    {
        while(~fscanf(file1,"%I64d %s %d %d %s",&tep.num,tep.name,&tep.sex,&tep.grade,tep.major))
        {
            stu.push_back(tep);
        }
    }
    else
    {
        printf("The file <%s> can not be opened.\n",datas);//打开操作不成功
    }
    if((file2=fopen(datac,"a+"))!=NULL)
    {
        int p;
        while(~fscanf(file2,"%d %s %d %d %d %I64d %I64d %d",&cc.num,cc.name,&cc.date.year,&cc.date.month,&cc.date.day,&cc.huizhang,&cc.mishu,&p))
        {
            cc.studen.clear();
            for(i=0; i<p; i++)
            {
                fscanf(file2,"%I64d",&tepp);
                cc.studen.push_back(tepp);
            }
            C.push_back(cc);
        }
    }
    else
    {
        printf("The file <%s> can not be opened.\n",datac);//打开操作不成功
    }
//   printf("%d\n",C[1].studen)
    //  return 0;
    fclose(file1);//读入社团数据
    fclose(file2);
    /* int d=stu.size();
       for(i=0;i<d;i++)
       {
           printf("%lld %s %d %d %s\n",stu[i].num,stu[i].name,stu[i].sex,stu[i].grade,stu[i].major);
       }
       return 0;*/
    while(1)
    {
        //   int ad=stu.size();
        sort(stu.begin(),stu.end(),cmp);
        system("cls");
        tab1();
        char a;
        a=getch();
        if(a=='1')//学生1
        {
            system("cls");
            tab2();
            a=getch();
            while(a==32||a=='\b')
            {
                a=getch();
            }
            if(a=='1')//添加新学生11
            {
                system("cls");
                if(Addstudent(tep)==0)
                {
                    puts("");
                    pt();
                    puts("■添加失败");
                }
                system("pause");
            }
            else if(a=='2')//操作已添加的学生12
            {
                system("cls");
                int tt=0;
                while(1)
                {
                    puts("");
                    pt();
                    puts("■操作已添加的学生:");
                    pt();
                    printf("■输入学号:");
                    gets(ss);
                    tt=judge1(ss);
                    //   printf("%d\n",tt);
                    if(tt>=0) break;
                    else
                    {
                        pt();
                        if(tt==-2)
                            printf("■学号格式错误,按Y重新输入,按N退出");
                        else printf("■该学生不存在,按Y重新输入,按N退出");
                        a=getch();
                        while(YNjudge(a)==0)
                        {
                            a=getch();
                        }
                        if(a=='N'||a=='n') break;
                        system("cls");
                    }
                }
                if(tt>=0)//已找到此学生,下标为tt
                {
                    while(1)
                    {
                        system("cls");
                        pt();
                        puts("■请确认学生信息:");
                        //  printf("201522332\tklc\tnan\tgrade1\tcomputerscience\n");//学号\t姓名\t性别\t年级\t专业
                        tabs();
                        Printstin(stu[tt]);
                        tab3();
                        a=getch();
                        while(a==32||a=='\b')
                        {
                            a=getch();
                        }
                        //学生操作
                        if(a=='1')//修改学生信息121
                        {
                            while(1)
                            {
                                system("cls");
                                pt();
                                puts("■请确认学生信息:");
                                tabs();
                                Printstin(stu[tt]);
                                pt();
                                tabs121();
                                a=getch();
                                while(a=='\b'||a==32)
                                    a=getch();
                                if(a=='1')
                                {
                                    puts("");
                                    while(1)
                                    {
                                        pt();
                                        printf("■输入要修改的姓名:");
                                        gets(ss);
                                        if(judge2(ss)==0)
                                        {
                                            pt();
                                            printf("■姓名格式不正确,重新输入按Y,退出按N");
                                            a=getch();
                                            puts("");
                                            while(YNjudge(a)==0)
                                                a=getch();
                                            if(a=='n'||a=='N')  break;
                                        }
                                        else
                                        {
                                            pt();
                                            printf("■修改之后的姓名为%s,确定按Y,取消按N\n",ss);
                                            a=getch();
                                            while(YNjudge(a)==0)
                                                a=getch();
                                            if(a=='Y'||a=='y')
                                            {
                                                strcpy(stu[tt].name,ss);
                                                pt();
                                                puts("■修改成功!");
                                                system("pause");
                                            }
                                            break;
                                        }
                                    }
                                }
                                else if(a=='2')//修改性别
                                {
                                    puts("");
                                    while(1)
                                    {
                                        pt();
                                        printf("■输入要修改的性别,男1,女2:");
                                        gets(ss);
                                        if(judge3(ss)==0)
                                        {
                                            pt();
                                            printf("■性别格式不正确,重新输入按Y,退出按N\n");
                                            a=getch();
                                            while(YNjudge(a)==0)
                                                a=getch();
                                            if(a=='n'||a=='N')  break;
                                        }
                                        else
                                        {
                                            pt();
                                            printf("■修改之后的性别为 ");
                                            if(ss[0]=='1') printf("男");
                                            else printf("女");
                                            printf("■确定按Y,取消按N\n");
                                            a=getch();
                                            while(YNjudge(a)==0)
                                                a=getch();
                                            if(a=='Y'||a=='y')
                                            {
                                                stu[tt].sex=ss[0]-'0';
                                                pt();
                                                puts("■修改成功!");
                                                system("pause");
                                            }
                                            break;
                                        }
                                    }
                                }
                                else if(a=='3')//修改年级
                                {
                                    puts("");
                                    while(1)
                                    {
                                        pt();
                                        printf("■输入要修改的年级:");
                                        gets(ss);
                                        if(judge4(ss)==0)
                                        {
                                            pt();
                                            printf("■年级格式不正确,重新输入按Y,退出按N");
                                            a=getch();
                                            puts("");
                                            while(YNjudge(a)==0)
                                                a=getch();
                                            if(a=='n'||a=='N')  break;
                                        }
                                        else
                                        {
                                            pt();
                                            printf("■修改之后的年级为%s,确定按Y,取消按N\n",ss);
                                            a=getch();
                                            while(YNjudge(a)==0)
                                                a=getch();
                                            if(a=='Y'||a=='y')
                                            {
                                                stu[tt].grade=change(ss);
                                                pt();
                                                puts("■修改成功!");
                                                system("pause");
                                            }
                                            break;
                                        }
                                    }
                                }
                                else if(a=='4')//修改专业
                                {
                                    puts("");
                                    while(1)
                                    {
                                        pt();
                                        printf("■输入要修改的专业:");
                                        gets(ss);
                                        if(judge2(ss)==0)
                                        {
                                            pt();
                                            printf("■年级格式不正确,重新输入按Y,退出按N");
                                            a=getch();
                                            puts("");
                                            while(YNjudge(a)==0)
                                                a=getch();
                                            if(a=='n'||a=='N')  break;
                                        }
                                        else
                                        {
                                            pt();
                                            printf("■修改之后的专业为%s,确定按Y,取消按N\n",ss);
                                            a=getch();
                                            while(YNjudge(a)==0)
                                                a=getch();
                                            if(a=='Y'||a=='y')
                                            {
                                                strcpy(stu[tt].major,ss);
                                                pt();
                                                puts("■修改成功!");
                                                system("pause");
                                            }
                                            break;
                                        }
                                    }
                                }
                                else break;
                                //     student teps;
                            }
                            continue;
                        }
                        else if(a=='2')//删除学生OK
                        {
                            printf("■是否删除该学生?是按Y,否按N");
                            a=getch();
                            while(YNjudge(a)==0)
                                a=getch();
                            if(a=='Y'||a=='y')
                            {
                                pt();
                                /**找到包含此学生的社团,并删除该学生学号**/
                                Del(stu[tt].num);
                                stu.erase(stu.begin()+tt);
                                //  for(vector<student>::iterator it;it!=stu)
                                puts("\n\t\t\t■已删除");
                                system("pause");
                                break;
                            }
                            continue;
                        }
                        else if(a=='3')//stu[tt]学生加入社团
                        {
                            Addstutocor(stu[tt].num);//查找社团是否存在,查找社团里是否有该学生;
                            continue;//返回
                        }
                        else if(a=='4')//学生退出社团
                        {
                            //输入社团编号
                            Quitc(stu[tt].num);
                            continue;
                        }
                        else if(a=='5')//修改学生在社团中的信息
                        {
                            //输入社团编号
                            Setstuinc(stu[tt].num);
                            continue;
                        }
                        break;//must
                        system("pause");
                        //以上为找到学生下标为tt
                    }
                }

            }
        }
        /**************************************************************/
        else if(a=='2')//社团
        {
            system("cls");
            tab4();
            a=getch();
            while(a==32||a=='\b')
            {
                a=getch();
            }
            if(a=='1')//添加一个社团OK
            {
                system("cls");
                if(AddCor()==0)
                {
                    puts("");
                    pt();
                    puts("■添加失败");
                }
            }
            else if(a=='2')//操作已添加社团
            {
                system("cls");
                tab5();
                a=getch();
                while(a==32||a=='\b')
                {
                    a=getch();
                }
                if(a=='1')//删除社团OK
                {
                    Delc();
                }
                else if(a=='2')//修改社团信息221ok
                {
                    Setcor();
                }
                else if(a=='3')//查询社团详细信息OK
                {
                    Lookc();
                }
                else if(a=='4')//显示所有社团简略信息OK
                {
                    ShowAll();
                }
            }
            system("pause");
        }
        else break;
    }
    //存入文件
    if((file1=fopen(datas,"w"))!=NULL)
    {
        int d=stu.size();
        for(i=0; i<d; i++)
        {
            fprintf(file1,"%I64d %s %d %d %s\n",stu[i].num,stu[i].name,stu[i].sex,stu[i].grade,stu[i].major);//+%d下面再输出数字
        }
    }
    else  printf("The file <%s> can not be opened.\n",datas);//打开操作不成功
    if((file2=fopen(datac,"w"))!=NULL)
    {
        // 社团编号 社团名 成立时间 会长 秘书学号 成员总数n n个学号
        int d=C.size();
        for(i=0; i<d; i++)
        {
            fprintf(file2,"%d %s %d %d %d %I64d %I64d %d",C[i].num,C[i].name,C[i].date.year,C[i].date.month,C[i].date.day,C[i].huizhang,C[i].mishu,C[i].studen.size());//+%d下面再输出数字
            int p=C[i].studen.size();
            for(int j=0; j<p; j++)
                fprintf(file2," %I64d",C[i].studen[j]);
            fprintf(file2,"\n");
        }
    }
    else  printf("The file <%s> can not be opened.\n",datac);//打开操作不成功
    fclose(file1);
    fclose(file2);
    //  Sleep(1000);
    //  system("pause");
    return 0;
}
