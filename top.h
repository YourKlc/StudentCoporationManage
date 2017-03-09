#ifndef TOP_H_INCLUDED
#define TOP_H_INCLUDED

void pt()//打印函数
{
    printf("\t\t\t");
}

void tab1()//主菜单
{
    printf("\n\t\t\t■■■■■■■■■■■■■\n");
    printf("\t\t\t■   1.学生操作\t\t■\n");
    printf("\t\t\t■   2.社团操作\t\t■\n");
    printf("\t\t\t■   按其他键退出\t■\n");
    printf("\t\t\t■■■■■■■■■■■■■\n");
    pt();
}


void tab2()//学生1
{
    printf("\n\t\t\t■■■■■■■■■■■■■\n");
    printf("\t\t\t■   1.添加一个新的学生\t■\n");
    printf("\t\t\t■   2.操作已添加的学生\t■\n");
    printf("\t\t\t■   按其他键返回\t■\n");
    printf("\t\t\t■■■■■■■■■■■■■\n");
    pt();
}

void tab3()//学生2
{
    printf("\n\t\t\t■■■■■■■■■■■■■■■■■\n");
    printf("\t\t\t■   1.修改学生信息\t\t■\n");
    printf("\t\t\t■   2.删除学生\t\t\t■\n");
    printf("\t\t\t■   3.学生加入社团\t\t■\n");
    printf("\t\t\t■   4.学生退出社团\t\t■\n");
    printf("\t\t\t■   5.修改学生在社团中的信息\t■\n");
    printf("\t\t\t■   按其他键返回\t\t■\n");
    printf("\t\t\t■■■■■■■■■■■■■■■■■\n");
    pt();
}

void tabs121()//修改学生信息121
{
    printf("\n\t\t\t■■■■■■■■■■■■■■■■■\n");
    printf("\t\t\t■   1.修改姓名\t\t\t■\n");
    printf("\t\t\t■   2.修改性别\t\t\t■\n");
    printf("\t\t\t■   3.修改年级\t\t\t■\n");
    printf("\t\t\t■   4.修改专业\t\t\t■\n");
    printf("\t\t\t■   按其他键返回\t\t■\n");
    printf("\t\t\t■■■■■■■■■■■■■■■■■\n");
    pt();
}
void tabs122()//修改学生在社团中的信息122
{
    pt();
    printf("■修改在社团中的信息");
    printf("\n\t\t\t■■■■■■■■■■■■■■■■■\n");
    printf("\t\t\t■   1.改为会长\t\t\t■\n");
    printf("\t\t\t■   2.改为秘书\t\t\t■\n");
    printf("\t\t\t■   3.改为普通会员\t\t■\n");
    printf("\t\t\t■   按其他键返回\t\t■\n");
    printf("\t\t\t■■■■■■■■■■■■■■■■■\n");
    pt();
}
void tabc221()//修改社团信息221
{
    printf("\n\t\t\t■■■■■■■■■■■■■■■■■\n");
    printf("\t\t\t■   1.修改社团名\t\t■\n");
    printf("\t\t\t■   2.修改会长\t\t\t■\n");
    printf("\t\t\t■   3.修改秘书\t\t\t■\n");
    // printf("\t\t\t■   4.删除成员\t\t\t■\n");
    printf("\t\t\t■   按其他键返回\t\t■\n");
    printf("\t\t\t■■■■■■■■■■■■■■■■■\n");
    pt();
}
void tabs()//学生信息
{
    pt();
    printf("学号\t\t姓名\t性别\t年级\t专业\t\n");
}
void tabc()//社团信息
{
    pt();
    char sw[]="会长(学号)";
    char se[]="秘书(学号)";
    printf("社团编号 社团名\t成立时间   %-22s%-22s 成员总数\n",sw,se);//,sw,se);
}
void tab4()//社团
{
    printf("\n\t\t\t■■■■■■■■■■■■■\n");
    printf("\t\t\t■   1.添加一个新的社团\t■\n");
    printf("\t\t\t■   2.操作已添加社团\t■\n");
    printf("\t\t\t■   按其他键返回\t■\n");
    printf("\t\t\t■■■■■■■■■■■■■\n");
    pt();
}

void tab5()//操作已添加社团
{
    printf("\n\t\t\t■■■■■■■■■■■■■\n");
    printf("\t\t\t■   1.删除社团\t\t■\n");
    printf("\t\t\t■   2.修改社团信息 \t■\n");
    printf("\t\t\t■   3.查询社团信息\t■\n");//输入您要查询的社团编号
    printf("\t\t\t■   4.所有社团简略信息 ■\n");
    printf("\t\t\t■   按其他键返回\t■\n");
    printf("\t\t\t■■■■■■■■■■■■■\n");
    pt();
}

void Gotoxy(int x, int y) //定位到第y行的第x列
{
    // int xx=0x0b;
    HANDLE hOutput;
    COORD loc;
    loc.X = x;
    loc.Y=y;
    hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOutput, loc);
}

/**其他**/
LL change(char l[])//把字符串转化为long long
{
    LL s=0;
    int d=strlen(l);
    for(int i=0; i<d; i++)
    {
        s*=10;
        s+=l[i]-'0';
    }
    return s;
}

/**输入合法性判断**/
int YNjudge(char c)
{
    if(c=='Y'||c=='y'||c=='n'||c=='N') return 1;
    return 0;
}
int judge1(char m[])//学号合法性判断+判重 -2是格式不对,>=0是重合,-1是没有
{
    int d=strlen(m);
    if(d>20||d<=0) return -2;
    for(int i=0; i<d; i++)
    {
        if(m[i]<'0'||m[i]>'9') return -2;
    }
    long long s=change(m);
    d=stu.size();
    //printf("%d\n",d);
    for(int i=0; i<d; i++)
    {
        // printf("%lld %lld\n",stu[i].num,s);
        if(stu[i].num==s) return i;
        if(stu[i].num>s) break;
    }
    return -1;
}

int judge2(char m[])//姓名&专业合法性判断
{
    int d=strlen(m);
    if(d>30||d<=0) return 0;
    for(int i=0; i<d; i++)
    {
        if(m[i]==' '||m[i]=='\r') return 0;
    }
    return 1;
}

int judge3(char m[])//性别合法性判断
{
    int d=strlen(m);
    if(d==1)
    {
        if(m[0]=='1'||m[0]=='2') return 1;
    }
    return 0;
}
int judge4(char m[])//年级合法性判断
{
    int d=strlen(m);
    if(d>5) return 0;
    for(int i=0; i<d; i++)
    {
        if(m[i]<'0'||m[i]>'9') return 0;
    }
    return 1;
}
/**
     **/
bool Cmp(const student &A,const student &B)
{
    return A.num<B.num;
}


#endif // TOP_H_INCLUDED
