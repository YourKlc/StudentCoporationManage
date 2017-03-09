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

void Printstin(struct student s)//��ӡѧ����Ϣ
{
    pt();
    // printf("201522332\tklc\tnan\tgrade1\tcomputerscience\n");//ѧ��\t����\t�Ա�\t�꼶\tרҵ
    printf("%-10I64d\t%s\t",s.num,s.name);
    if(s.sex==FEMALE) printf("Ů");
    else if(s.sex==MALE) printf("��");
    else printf("δ֪�Ա�");
    printf("\t%d�꼶\t%s\n",s.grade,s.major);
    /**�ҵ�������ѧ��������,�����浽string S��**/
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
        puts("�Ѽ��������:");
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
int Addstudent(struct student &tep)//���ѧ��
{
    pt();
    puts("�������ѧ��:");
    //int et=0;
    char c;
    char ss[100];
    while(1)
    {
        pt();
        printf("������ѧ��:");
        gets(ss);
        int t=judge1(ss);
        if(t==-1)
        {
            tep.num=change(ss);
            while(1)
            {
                pt();
                printf("����������:");
                gets(ss);
                if(judge2(ss)==1)
                {
                    strcpy(tep.name,ss);
                    while(1)
                    {
                        pt();
                        printf("������һ�����ִ����Ա�:1Ϊ��,2ΪŮ:");
                        gets(ss);
                        if(judge3(ss)==1)
                        {
                            tep.sex=ss[0]-'0';
                            while(1)
                            {

                                pt();
                                printf("�������꼶(������):");
                                gets(ss);
                                if(judge4(ss)==1)
                                {
                                    tep.grade=change(ss);
                                    while(1)
                                    {
                                        pt();
                                        printf("������רҵ:");
                                        gets(ss);
                                        if(judge2(ss)==1)
                                        {
                                            strcpy(tep.major,ss);
                                            system("cls");
                                            pt();
                                            puts("����ȷ�ϸ�ѧ����Ϣ:");
                                            tabs();
                                            Printstin(tep);
                                            pt();
                                            puts("��ȷ����Ӱ�Y,ȡ����N");
                                            c=getch();
                                            while(YNjudge(c)==0)
                                            {
                                                c=getch();
                                            }
                                            if(c=='Y'||c=='y')
                                            {
                                                //���
                                                stu.push_back(tep);
                                                sort(stu.begin(),stu.end(),Cmp);
                                                pt();
                                                puts("���ѳɹ����");
                                            }
                                            else
                                            {
                                                pt();
                                                puts("����ȡ�����");
                                            }
                                            return 1;
                                        }
                                        else
                                        {
                                            pt();
                                            printf("��רҵ��ʽ����,��Y��������,��N�˳�");
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
                                    printf("���꼶��ʽ����,��Y��������,��N�˳�");
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
                            printf("���Ա��ʽ����,��Y��������,��N�˳�");
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
                    printf("��������ʽ����,��Y��������,��N�˳�");
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
                printf("��ѧ�Ÿ�ʽ����,��Y��������,��N�˳�");
            else printf("����ѧ���Ѵ���,��Y��������,��N�˳�");
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

int Getstuname(long long num,char ss[])//�õ�ѧ��Ϊnum��ѧ���������浽ss��,�з���1,�޷���0
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
int Findstuinc(long long num,int p)//���±�Ϊp��������Ѱ��ѧ��Ϊnum��ѧ��,�з���ѧ���±�+1,�޷���0
{
    int i,d=C[p].studen.size();
    for(i=0; i<d; i++)
        if(num==C[p].studen[i])
        {
            return i+1;
        }
    return 0;
}
/**�ҵ�������ѧ��������,��ɾ����ѧ��ѧ��**/
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
int judgec1(char m[])//���ű�źϷ����ж�+���� -2�Ǹ�ʽ����,>=0���غ�,-1��û��
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

int AddCor()//struct Corporation &c)//�������
{
    pt();
    puts("�����������:");
    struct Corporation c;
    char m;
    char ss[100];
    while(1)
    {
        pt();
        printf("���������ű��:");
        gets(ss);
        int t=judgec1(ss);
        if(t==-1)
        {
            c.num=change(ss);
            while(1)
            {
                pt();
                printf("������������:");
                gets(ss);
                if(judge2(ss)==1)
                {
                    strcpy(c.name,ss);
                    while(1)
                    {
                        pt();
                        printf("���������ų���ʱ��(ע��:һ��ȷ���޷�����,��ʽΪXXXX-XX-XX):");
                        gets(ss);
                        if(judgec2(ss,c)==1)
                        {
                            system("cls");
                            pt();
                            puts("����ȷ�ϸ�������Ϣ:");
                            c.Show();
                            pt();
                            puts("��ȷ����Ӱ�Y,ȡ����N");
                            m=getch();
                            while(YNjudge(m)==0)
                            {
                                m=getch();
                            }
                            if(m=='Y'||m=='y')
                            {
                                //���
                                C.push_back(c);
                                int d=C.size();
                                sort(C.begin(),C.end(),ccmp);
                                for(int i=0; i<d; i++)
                                    sort(C[i].studen.begin(),C[i].studen.end());
                                ///���� ,���ű������ÿ������ѧ��ѧ������,
                                pt();
                                puts("���ѳɹ����");
                            }
                            else
                            {
                                pt();
                                puts("����ȡ�����");
                            }
                            return 1;
                        }
                        else
                        {
                            pt();
                            printf("���������ڸ�ʽ����,��Y��������,��N�˳�");
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
                    printf("����������ʽ����,��Y��������,��N�˳�");
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
                printf("����Ÿ�ʽ����,��Y��������,��N�˳�");
            else printf("���������Ѵ���,��Y��������,��N�˳�");
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
int Delc()//ɾ������
{
    char ss[100];
    while(1)
    {
        system("cls");
        pt();
        printf("��������Ҫɾ�������ű��:");
        gets(ss);
        int t=judgec1(ss);
        if(t>=0)
        {
            pt();
            puts("��ȷ��Ҫɾ����������Ϣ:");
            C[t].Show();
            pt();
            printf("���Ƿ�ɾ��?�ǰ�Y,��N:");
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
                puts("���ɹ�ɾ��!");
            }
            else puts("��ȡ��ɾ��");

            return 1;
        }
        else
        {
            pt();
            if(t==-2)
                printf("����Ÿ�ʽ����,��Y��������,��N�˳�");
            else printf("�������Ų�����,��Y��������,��N�˳�");
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
int Lookc()//��ѯ��ϸ��Ϣ
{
    char ss[100];
    char m;
    while(1)
    {
        system("cls");
        pt();
        printf("��������Ҫ���ҵ����ű��:");
        gets(ss);
        int t=judgec1(ss);
        if(t>=0)
        {
            C[t].Show2();
            puts("");
            pt();
            printf("���������Ұ�Y,�������˵���N:");
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
                printf("����Ÿ�ʽ����,��Y��������,��N�˳�");
            else printf("�������Ų�����,��Y��������,��N�˳�");
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
void ShowAll()//��ʾ�������ż�����Ϣ
{
    puts("");
    tabc();
    int d=C.size();
    for(int i=0; i<d; i++)
        C[i].ShortShow();
}

void Setcor()//�޸�������Ϣ
{
    char ss[100],a;
    while(1)
    {
        system("cls");
        pt();
        printf("���޸�������Ϣ:\n");
        pt();
        printf("��������Ҫ�޸ĵ����ű��:");
        gets(ss);
        int t=judgec1(ss);//tΪ���ű��
        if(t>=0)
        {
            pt();
            puts("��ȷ��Ҫ�޸ĵ�������Ϣ:");
            C[t].Show();
            pt();
            printf("���Ƿ��޸ĸ�����?�ǰ�Y,��N:");
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
                    puts("��ȷ��Ҫ�޸ĵ�������Ϣ:");
                    C[t].Show();
                    tabc221();
                    a=getch();
                    while(a=='\b'||a==32)
                        a=getch();
                    if(a=='1')//�޸�������OK
                    {
                        puts("");
                        while(1)
                        {
                            pt();
                            printf("������Ҫ�޸ĵ�������:");
                            gets(ss);
                            if(judge2(ss)==1)
                            {
                                pt();
                                printf("���޸�֮���������Ϊ:%s,ȷ����Y,ȡ����N\n",ss);
                                a=getch();
                                while(YNjudge(a)==0)
                                    a=getch();
                                if(a=='Y'||a=='y')
                                {
                                    strcpy(C[t].name,ss);
                                    pt();
                                    puts("���޸ĳɹ�!");
                                    system("pause");
                                }
                                break;
                            }
                            else
                            {
                                pt();
                                printf("����������ʽ����ȷ,�������밴Y,�˳���N");
                                a=getch();
                                puts("");
                                while(YNjudge(a)==0)
                                    a=getch();
                                if(a=='n'||a=='N')  break;
                            }
                        }
                    }
                    else if(a=='2')//�޸Ļ᳤
                    {
                        puts("");
                        while(1)
                        {
                            pt();
                            printf("������Ҫ�޸ĵĻ᳤ѧ��:");
                            gets(ss);
                            int tt=judge1(ss);//ttΪѧ���±�
                            if(tt>=0)
                            {
                                int qt=Findstuinc(change(ss),t);
                                if(qt==1)
                                {
                                    pt();
                                    printf("���޸�֮��Ļ᳤ѧ��Ϊ:%s,",ss);
                                    printf("������Ϊ%s,ȷ����Y,ȡ����N\n",stu[tt].name);
                                    a=getch();
                                    while(YNjudge(a)==0)
                                        a=getch();
                                    if(a=='Y'||a=='y')
                                    {
                                        C[t].huizhang=change(ss);
                                        pt();
                                        puts("���޸ĳɹ�!");
                                        system("pause");
                                    }
                                    break;
                                }
                                else
                                {
                                    pt();
                                    printf("���������޴�ѧ��,��Y��������,��N�˳�");
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
                                    printf("��ѧ�Ÿ�ʽ����,��Y��������,��N�˳�");
                                else printf("����ѧ��δ�Ǽ�,��Y��������,��N�˳�");
                                a=getch();
                                puts("");
                                while(YNjudge(a)==0)
                                    a=getch();
                                if(a=='n'||a=='N')  break;
                            }
                        }
                    }
                    else if(a=='3')//�޸�����
                    {
                        puts("");
                        while(1)
                        {
                            pt();
                            printf("������Ҫ�޸ĵ�����ѧ��:");
                            gets(ss);
                            int tt=judge1(ss);//ttΪѧ���±�
                            if(tt>=0)
                            {
                                int qt=Findstuinc(change(ss),t);
                                if(qt==1)
                                {
                                    pt();
                                    printf("���޸�֮�������ѧ��Ϊ:%s,",ss);
                                    printf("������Ϊ%s,ȷ����Y,ȡ����N\n",stu[tt].name);
                                    a=getch();
                                    while(YNjudge(a)==0)
                                        a=getch();
                                    if(a=='Y'||a=='y')
                                    {
                                        C[t].mishu=change(ss);
                                        pt();
                                        puts("���޸ĳɹ�!");
                                        system("pause");
                                    }
                                    break;
                                }
                                else
                                {
                                    pt();
                                    printf("���������޴�ѧ��,��Y��������,��N�˳�");
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
                                    printf("��ѧ�Ÿ�ʽ����,��Y��������,��N�˳�");
                                else printf("����ѧ��δ�Ǽ�,��Y��������,��N�˳�");
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
            else puts("��ȡ���޸�");

            return ;
        }
        else
        {
            pt();
            if(t==-2)
                printf("����Ÿ�ʽ����,��Y��������,��N�˳�");
            else printf("�������Ų�����,��Y��������,��N�˳�");
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

void Addstutocor(long long s)//��������,���Ȳ��������Ƿ����,�����������Ƿ��и�ѧ��,sΪѧ��
/********************************************************************************************************************************/
{
    char ss[100];
    puts("");
    while(1)
    {
        pt();
        printf("������Ҫ��������ű��:");
        gets(ss);
        int t=judgec1(ss);//tΪ���ű��
        if(t>=0)//�����Ŵ���,���ѧ���Ƿ��ڸ�������,�������,���������,��sort���������ѧ��
        {
            int tt=Findstuinc(s,t);
            if(tt==0)
            {
                C[t].studen.push_back(s);
                C[t].Sort();
                pt();
                printf("������ɹ�!");
                system("pause");
                break;
            }
            else
            {
                pt();
                printf("����ѧ������������,��Y��������,��N�˳�");
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
                printf("����Ÿ�ʽ����,��Y��������,��N�˳�");
            else printf("�������Ų�����,��Y��������,��N�˳�");
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
void Quitc(long long s)//�˳�����,���Ȳ��������Ƿ����,�����������Ƿ��и�ѧ��,sΪѧ��
/********************************************************************************************************************************/
{
    char ss[100];
    puts("");
    while(1)
    {
        pt();
        printf("������Ҫ�˳������ű��:");
        gets(ss);
        int t=judgec1(ss);//tΪ���ű��
        if(t>=0)//�����Ŵ���,���ѧ���Ƿ��ڸ�������,�������,���������,��sort���������ѧ��
        {
            int tt=Findstuinc(s,t);
            if(tt!=0)
            {
                C[t].studen.erase(C[t].studen.begin()+tt-1);
                pt();
                if(C[t].huizhang==s) C[t].huizhang=0;
                if(C[t].mishu==s) C[t].mishu=0;
                printf("���˳��ɹ�!");
                system("pause");
                break;
            }
            else
            {
                pt();
                printf("����ѧ�����ڸ�������,��Y��������,��N�˳�");
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
                printf("����Ÿ�ʽ����,��Y��������,��N�˳�");
            else printf("�������Ų�����,��Y��������,��N�˳�");
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
void Setstuinc(LL s)//�޸�ѧ���������е���Ϣ
{
    char ss[100],a;
    puts("");
    while(1)
    {
        pt();
        printf("������Ҫ�޸ĵ����ű��:");
        gets(ss);
        int t=judgec1(ss);//tΪ���ű��
        if(t>=0)//�����Ŵ���,���ѧ���Ƿ��ڸ�������,
        {

            int tt=Findstuinc(s,t);
            if(tt!=0)//���ѧ���Ƿ��ڸ�������, ttΪ�±�+1
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
                    printf("���޸ĳɹ�!");
                    system("pause");
                    return;
                }
                else break;

            }
            else
            {
                pt();
                printf("����ѧ�����ڸ�������,��Y��������,��N�˳�");
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
                printf("�����ű�Ÿ�ʽ����,��Y��������,��N�˳�");
            else printf("�������Ų�����,��Y��������,��N�˳�");
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
    DrawMenuBar(GetConsoleWindow());//���ùرհ�ť

    //aΪһ���ַ�,i�Ǹ�int����,stu�Ǵ�ѧ��������
    //ѧ��\t����\t�Ա�\t�꼶\tרҵ
    //num name sex grade major
    //longlong string int int string


    struct student  tep;
    struct Corporation cc;

    char ss[100];//��������Ϣ;
    system("color f0");
    system("cls");
    system("mode con cols=130 lines=35");//�� ��

    int i;
    LL tepp;//��ʼѧ����
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
        printf("The file <%s> can not be opened.\n",datas);//�򿪲������ɹ�
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
        printf("The file <%s> can not be opened.\n",datac);//�򿪲������ɹ�
    }
//   printf("%d\n",C[1].studen)
    //  return 0;
    fclose(file1);//������������
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
        if(a=='1')//ѧ��1
        {
            system("cls");
            tab2();
            a=getch();
            while(a==32||a=='\b')
            {
                a=getch();
            }
            if(a=='1')//�����ѧ��11
            {
                system("cls");
                if(Addstudent(tep)==0)
                {
                    puts("");
                    pt();
                    puts("�����ʧ��");
                }
                system("pause");
            }
            else if(a=='2')//��������ӵ�ѧ��12
            {
                system("cls");
                int tt=0;
                while(1)
                {
                    puts("");
                    pt();
                    puts("����������ӵ�ѧ��:");
                    pt();
                    printf("������ѧ��:");
                    gets(ss);
                    tt=judge1(ss);
                    //   printf("%d\n",tt);
                    if(tt>=0) break;
                    else
                    {
                        pt();
                        if(tt==-2)
                            printf("��ѧ�Ÿ�ʽ����,��Y��������,��N�˳�");
                        else printf("����ѧ��������,��Y��������,��N�˳�");
                        a=getch();
                        while(YNjudge(a)==0)
                        {
                            a=getch();
                        }
                        if(a=='N'||a=='n') break;
                        system("cls");
                    }
                }
                if(tt>=0)//���ҵ���ѧ��,�±�Ϊtt
                {
                    while(1)
                    {
                        system("cls");
                        pt();
                        puts("����ȷ��ѧ����Ϣ:");
                        //  printf("201522332\tklc\tnan\tgrade1\tcomputerscience\n");//ѧ��\t����\t�Ա�\t�꼶\tרҵ
                        tabs();
                        Printstin(stu[tt]);
                        tab3();
                        a=getch();
                        while(a==32||a=='\b')
                        {
                            a=getch();
                        }
                        //ѧ������
                        if(a=='1')//�޸�ѧ����Ϣ121
                        {
                            while(1)
                            {
                                system("cls");
                                pt();
                                puts("����ȷ��ѧ����Ϣ:");
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
                                        printf("������Ҫ�޸ĵ�����:");
                                        gets(ss);
                                        if(judge2(ss)==0)
                                        {
                                            pt();
                                            printf("��������ʽ����ȷ,�������밴Y,�˳���N");
                                            a=getch();
                                            puts("");
                                            while(YNjudge(a)==0)
                                                a=getch();
                                            if(a=='n'||a=='N')  break;
                                        }
                                        else
                                        {
                                            pt();
                                            printf("���޸�֮�������Ϊ%s,ȷ����Y,ȡ����N\n",ss);
                                            a=getch();
                                            while(YNjudge(a)==0)
                                                a=getch();
                                            if(a=='Y'||a=='y')
                                            {
                                                strcpy(stu[tt].name,ss);
                                                pt();
                                                puts("���޸ĳɹ�!");
                                                system("pause");
                                            }
                                            break;
                                        }
                                    }
                                }
                                else if(a=='2')//�޸��Ա�
                                {
                                    puts("");
                                    while(1)
                                    {
                                        pt();
                                        printf("������Ҫ�޸ĵ��Ա�,��1,Ů2:");
                                        gets(ss);
                                        if(judge3(ss)==0)
                                        {
                                            pt();
                                            printf("���Ա��ʽ����ȷ,�������밴Y,�˳���N\n");
                                            a=getch();
                                            while(YNjudge(a)==0)
                                                a=getch();
                                            if(a=='n'||a=='N')  break;
                                        }
                                        else
                                        {
                                            pt();
                                            printf("���޸�֮����Ա�Ϊ ");
                                            if(ss[0]=='1') printf("��");
                                            else printf("Ů");
                                            printf("��ȷ����Y,ȡ����N\n");
                                            a=getch();
                                            while(YNjudge(a)==0)
                                                a=getch();
                                            if(a=='Y'||a=='y')
                                            {
                                                stu[tt].sex=ss[0]-'0';
                                                pt();
                                                puts("���޸ĳɹ�!");
                                                system("pause");
                                            }
                                            break;
                                        }
                                    }
                                }
                                else if(a=='3')//�޸��꼶
                                {
                                    puts("");
                                    while(1)
                                    {
                                        pt();
                                        printf("������Ҫ�޸ĵ��꼶:");
                                        gets(ss);
                                        if(judge4(ss)==0)
                                        {
                                            pt();
                                            printf("���꼶��ʽ����ȷ,�������밴Y,�˳���N");
                                            a=getch();
                                            puts("");
                                            while(YNjudge(a)==0)
                                                a=getch();
                                            if(a=='n'||a=='N')  break;
                                        }
                                        else
                                        {
                                            pt();
                                            printf("���޸�֮����꼶Ϊ%s,ȷ����Y,ȡ����N\n",ss);
                                            a=getch();
                                            while(YNjudge(a)==0)
                                                a=getch();
                                            if(a=='Y'||a=='y')
                                            {
                                                stu[tt].grade=change(ss);
                                                pt();
                                                puts("���޸ĳɹ�!");
                                                system("pause");
                                            }
                                            break;
                                        }
                                    }
                                }
                                else if(a=='4')//�޸�רҵ
                                {
                                    puts("");
                                    while(1)
                                    {
                                        pt();
                                        printf("������Ҫ�޸ĵ�רҵ:");
                                        gets(ss);
                                        if(judge2(ss)==0)
                                        {
                                            pt();
                                            printf("���꼶��ʽ����ȷ,�������밴Y,�˳���N");
                                            a=getch();
                                            puts("");
                                            while(YNjudge(a)==0)
                                                a=getch();
                                            if(a=='n'||a=='N')  break;
                                        }
                                        else
                                        {
                                            pt();
                                            printf("���޸�֮���רҵΪ%s,ȷ����Y,ȡ����N\n",ss);
                                            a=getch();
                                            while(YNjudge(a)==0)
                                                a=getch();
                                            if(a=='Y'||a=='y')
                                            {
                                                strcpy(stu[tt].major,ss);
                                                pt();
                                                puts("���޸ĳɹ�!");
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
                        else if(a=='2')//ɾ��ѧ��OK
                        {
                            printf("���Ƿ�ɾ����ѧ��?�ǰ�Y,��N");
                            a=getch();
                            while(YNjudge(a)==0)
                                a=getch();
                            if(a=='Y'||a=='y')
                            {
                                pt();
                                /**�ҵ�������ѧ��������,��ɾ����ѧ��ѧ��**/
                                Del(stu[tt].num);
                                stu.erase(stu.begin()+tt);
                                //  for(vector<student>::iterator it;it!=stu)
                                puts("\n\t\t\t����ɾ��");
                                system("pause");
                                break;
                            }
                            continue;
                        }
                        else if(a=='3')//stu[tt]ѧ����������
                        {
                            Addstutocor(stu[tt].num);//���������Ƿ����,�����������Ƿ��и�ѧ��;
                            continue;//����
                        }
                        else if(a=='4')//ѧ���˳�����
                        {
                            //�������ű��
                            Quitc(stu[tt].num);
                            continue;
                        }
                        else if(a=='5')//�޸�ѧ���������е���Ϣ
                        {
                            //�������ű��
                            Setstuinc(stu[tt].num);
                            continue;
                        }
                        break;//must
                        system("pause");
                        //����Ϊ�ҵ�ѧ���±�Ϊtt
                    }
                }

            }
        }
        /**************************************************************/
        else if(a=='2')//����
        {
            system("cls");
            tab4();
            a=getch();
            while(a==32||a=='\b')
            {
                a=getch();
            }
            if(a=='1')//���һ������OK
            {
                system("cls");
                if(AddCor()==0)
                {
                    puts("");
                    pt();
                    puts("�����ʧ��");
                }
            }
            else if(a=='2')//�������������
            {
                system("cls");
                tab5();
                a=getch();
                while(a==32||a=='\b')
                {
                    a=getch();
                }
                if(a=='1')//ɾ������OK
                {
                    Delc();
                }
                else if(a=='2')//�޸�������Ϣ221ok
                {
                    Setcor();
                }
                else if(a=='3')//��ѯ������ϸ��ϢOK
                {
                    Lookc();
                }
                else if(a=='4')//��ʾ�������ż�����ϢOK
                {
                    ShowAll();
                }
            }
            system("pause");
        }
        else break;
    }
    //�����ļ�
    if((file1=fopen(datas,"w"))!=NULL)
    {
        int d=stu.size();
        for(i=0; i<d; i++)
        {
            fprintf(file1,"%I64d %s %d %d %s\n",stu[i].num,stu[i].name,stu[i].sex,stu[i].grade,stu[i].major);//+%d�������������
        }
    }
    else  printf("The file <%s> can not be opened.\n",datas);//�򿪲������ɹ�
    if((file2=fopen(datac,"w"))!=NULL)
    {
        // ���ű�� ������ ����ʱ�� �᳤ ����ѧ�� ��Ա����n n��ѧ��
        int d=C.size();
        for(i=0; i<d; i++)
        {
            fprintf(file2,"%d %s %d %d %d %I64d %I64d %d",C[i].num,C[i].name,C[i].date.year,C[i].date.month,C[i].date.day,C[i].huizhang,C[i].mishu,C[i].studen.size());//+%d�������������
            int p=C[i].studen.size();
            for(int j=0; j<p; j++)
                fprintf(file2," %I64d",C[i].studen[j]);
            fprintf(file2,"\n");
        }
    }
    else  printf("The file <%s> can not be opened.\n",datac);//�򿪲������ɹ�
    fclose(file1);
    fclose(file2);
    //  Sleep(1000);
    //  system("pause");
    return 0;
}
