#ifndef CORPORATION_H_INCLUDED
#define CORPORATION_H_INCLUDED
int Getname(long long num,char ss[])//�õ�ѧ��Ϊnum��ѧ���������浽ss��,�з���1,�޷���0
{
    int i,d=stu.size();
    for(i=0; i<d; i++)
        if(num==stu[i].num)
        {
            strcpy(ss,stu[i].name);
            break;
        }
    return 0;
}
bool cmpint(const LL A,const LL B)
{
    return A<B;
}
struct Time
{
    int year,month,day;
    Time(int y=0,int m=0,int d=0):year(y),month(m),day(d) {}
    void SetTime(int y,int m,int d)
    {
        year=y;
        month=m;
        day=d;
    }
};
struct Corporation
{
    // ���ű�� ������ ����ʱ�� �᳤ ����ѧ�� ��Ա����n n��ѧ��
    int num;//���ű��
    char  name[30];//������
    Time date;//����ʱ��,�ɼ̳�һ��ʱ����
    LL huizhang,mishu;
    vector<long long >studen;
    Corporation(int n=-1,const char s[]="δ����",int y=0,int m=0,int d=0,LL h=0,LL mm=0,int sd=0):num(n),date(y,m,d),huizhang(h),mishu(mm)
    {
        strcpy(name,s);
    }
    void Sort()
    {
        sort(studen.begin(),studen.end(),cmpint);
    }
    void ShortShow()
    {
        // ���ű�� ������ ����ʱ�� �᳤ ����ѧ�� ��Ա����n n��ѧ��
        pt();
        printf("%-9d%-7s%04d-%02d-%02d ",num,name,date.year,date.month,date.day);
//printf("%lld\n",mishu);
        if(huizhang!=0)
        {
            char ss[100];
            Getname(huizhang,ss);
            int w[20],top=0;
            long long p=huizhang;
            while(p)
            {
                w[top++]=p%10;
                p/=10;
            }
            int d=strlen(ss);
            ss[d++]='<';
            for(int i=top-1; i>=0; i--)
                ss[d++]=w[i]+'0';
            ss[d++]='>';
            ss[d]='\0';
            printf("%-22s",ss);
        }
        else
        {
            char ss[]="����";
            printf("%-22s",ss);
        }
        if(mishu!=0)
        {
            char ss[100];
            Getname(mishu,ss);
            int w[20],top=0;
            long long p=mishu;
            while(p)
            {
                w[top++]=p%10;
                p/=10;
            }
            int d=strlen(ss);
            ss[d++]='<';
            for(int i=top-1; i>=0; i--)
                ss[d++]=w[i]+'0';
            ss[d++]='>';
            ss[d]='\0';
            printf("%-24s",ss);
        }
        else
        {
            char ss[]="����";
            printf("%-24s",ss);
        }
        printf("%d\n",studen.size());

        //%-8s%s\t%d\n"
    }
    void Show()
    {
        tabc();
        pt();
        printf("%-9d%-7s%04d-%02d-%02d ",num,name,date.year,date.month,date.day);
//printf("%lld\n",mishu);
        if(huizhang!=0)
        {
            char ss[100];
            Getname(huizhang,ss);
            int w[20],top=0;
            long long p=huizhang;
            while(p)
            {
                w[top++]=p%10;
                p/=10;
            }
            int d=strlen(ss);
            ss[d++]='<';
            for(int i=top-1; i>=0; i--)
                ss[d++]=w[i]+'0';
            ss[d++]='>';
            ss[d]='\0';
            printf("%-22s",ss);
        }
        else
        {
            char ss[]="����";
            printf("%-22s",ss);
        }
        if(mishu!=0)
        {
            char ss[100];
            Getname(mishu,ss);
            int w[20],top=0;
            long long p=mishu;
            while(p)
            {
                w[top++]=p%10;
                p/=10;
            }
            int d=strlen(ss);
            ss[d++]='<';
            for(int i=top-1; i>=0; i--)
                ss[d++]=w[i]+'0';
            ss[d++]='>';
            ss[d]='\0';
            printf("%-24s",ss);
        }
        else
        {
            char ss[]="����";
            printf("%-24s",ss);
        }
        printf("%d\n",studen.size());
    }

    void Detail()//��ϸ��ʾok
    {

        int i,d=0,to=stu.size();
        pt();
        int j=0;
        int mm=studen.size();
        for(i=0; i<mm; i++)
        {
            for(; j<to; j++)
            {
                if(stu[j].num==studen[i])

                {
                    printf("%-8s",stu[j].name);
                    d++;
                    if(d==8)
                    {
                        puts("");
                        pt();
                        d=0;
                    }
                    j++;
                    break;
                }
            }
        }
    }
    void Show2()//һ��������ϸ��Ϣ
    {
        Show();
        if(studen.size()!=0)
        {
            pt();
            printf("���������г�Ա:\n");
            Detail();
        }
        else
        {
            pt();
            puts("���������޳�Ա");
        }
    }
};//����
int datemax(int y,int m)
{
    int p[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
    if(y%400==0||(y%4==0&&y%100!=0)) p[1]++;
    return p[m-1];
}
int changedate(char w[],int da,int db)
{
    int s=0;
    for(int i=da; i<=db; i++)
    {
        s*=10;
        s+=w[i]-'0';
    }
    return s;
}
int judgec2(char w[],struct Corporation &c)//���ų���ʱ��
{
    int d=strlen(w),i;
    if(d>10||d<9) return 0;
    for( i=0; i<4; i++)
        if(w[i]<'0'||w[i]>'9') return 0;
    for(i=5; i<7; i++)
        if(w[i]<'0'||w[i]>'9') return 0;
    for(i=8; i<10; i++)
        if(w[i]<'0'||w[i]>'9') return 0;
    if(w[4]!='-'||w[7]!='-') return 0;
    if(changedate(w,0,3)>2017||changedate(w,5,6)>12||changedate(w,8,9)>datemax(changedate(w,0,3),changedate(w,5,6))) return 0;
    c.date.SetTime(changedate(w,0,3),changedate(w,5,6),changedate(w,8,9));
    return 1;
}

#endif // CORPORATION_H_INCLUDED
