#ifndef TOP_H_INCLUDED
#define TOP_H_INCLUDED

void pt()//��ӡ����
{
    printf("\t\t\t");
}

void tab1()//���˵�
{
    printf("\n\t\t\t��������������������������\n");
    printf("\t\t\t��   1.ѧ������\t\t��\n");
    printf("\t\t\t��   2.���Ų���\t\t��\n");
    printf("\t\t\t��   ���������˳�\t��\n");
    printf("\t\t\t��������������������������\n");
    pt();
}


void tab2()//ѧ��1
{
    printf("\n\t\t\t��������������������������\n");
    printf("\t\t\t��   1.���һ���µ�ѧ��\t��\n");
    printf("\t\t\t��   2.��������ӵ�ѧ��\t��\n");
    printf("\t\t\t��   ������������\t��\n");
    printf("\t\t\t��������������������������\n");
    pt();
}

void tab3()//ѧ��2
{
    printf("\n\t\t\t����������������������������������\n");
    printf("\t\t\t��   1.�޸�ѧ����Ϣ\t\t��\n");
    printf("\t\t\t��   2.ɾ��ѧ��\t\t\t��\n");
    printf("\t\t\t��   3.ѧ����������\t\t��\n");
    printf("\t\t\t��   4.ѧ���˳�����\t\t��\n");
    printf("\t\t\t��   5.�޸�ѧ���������е���Ϣ\t��\n");
    printf("\t\t\t��   ������������\t\t��\n");
    printf("\t\t\t����������������������������������\n");
    pt();
}

void tabs121()//�޸�ѧ����Ϣ121
{
    printf("\n\t\t\t����������������������������������\n");
    printf("\t\t\t��   1.�޸�����\t\t\t��\n");
    printf("\t\t\t��   2.�޸��Ա�\t\t\t��\n");
    printf("\t\t\t��   3.�޸��꼶\t\t\t��\n");
    printf("\t\t\t��   4.�޸�רҵ\t\t\t��\n");
    printf("\t\t\t��   ������������\t\t��\n");
    printf("\t\t\t����������������������������������\n");
    pt();
}
void tabs122()//�޸�ѧ���������е���Ϣ122
{
    pt();
    printf("���޸��������е���Ϣ");
    printf("\n\t\t\t����������������������������������\n");
    printf("\t\t\t��   1.��Ϊ�᳤\t\t\t��\n");
    printf("\t\t\t��   2.��Ϊ����\t\t\t��\n");
    printf("\t\t\t��   3.��Ϊ��ͨ��Ա\t\t��\n");
    printf("\t\t\t��   ������������\t\t��\n");
    printf("\t\t\t����������������������������������\n");
    pt();
}
void tabc221()//�޸�������Ϣ221
{
    printf("\n\t\t\t����������������������������������\n");
    printf("\t\t\t��   1.�޸�������\t\t��\n");
    printf("\t\t\t��   2.�޸Ļ᳤\t\t\t��\n");
    printf("\t\t\t��   3.�޸�����\t\t\t��\n");
    // printf("\t\t\t��   4.ɾ����Ա\t\t\t��\n");
    printf("\t\t\t��   ������������\t\t��\n");
    printf("\t\t\t����������������������������������\n");
    pt();
}
void tabs()//ѧ����Ϣ
{
    pt();
    printf("ѧ��\t\t����\t�Ա�\t�꼶\tרҵ\t\n");
}
void tabc()//������Ϣ
{
    pt();
    char sw[]="�᳤(ѧ��)";
    char se[]="����(ѧ��)";
    printf("���ű�� ������\t����ʱ��   %-22s%-22s ��Ա����\n",sw,se);//,sw,se);
}
void tab4()//����
{
    printf("\n\t\t\t��������������������������\n");
    printf("\t\t\t��   1.���һ���µ�����\t��\n");
    printf("\t\t\t��   2.�������������\t��\n");
    printf("\t\t\t��   ������������\t��\n");
    printf("\t\t\t��������������������������\n");
    pt();
}

void tab5()//�������������
{
    printf("\n\t\t\t��������������������������\n");
    printf("\t\t\t��   1.ɾ������\t\t��\n");
    printf("\t\t\t��   2.�޸�������Ϣ \t��\n");
    printf("\t\t\t��   3.��ѯ������Ϣ\t��\n");//������Ҫ��ѯ�����ű��
    printf("\t\t\t��   4.�������ż�����Ϣ ��\n");
    printf("\t\t\t��   ������������\t��\n");
    printf("\t\t\t��������������������������\n");
    pt();
}

void Gotoxy(int x, int y) //��λ����y�еĵ�x��
{
    // int xx=0x0b;
    HANDLE hOutput;
    COORD loc;
    loc.X = x;
    loc.Y=y;
    hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOutput, loc);
}

/**����**/
LL change(char l[])//���ַ���ת��Ϊlong long
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

/**����Ϸ����ж�**/
int YNjudge(char c)
{
    if(c=='Y'||c=='y'||c=='n'||c=='N') return 1;
    return 0;
}
int judge1(char m[])//ѧ�źϷ����ж�+���� -2�Ǹ�ʽ����,>=0���غ�,-1��û��
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

int judge2(char m[])//����&רҵ�Ϸ����ж�
{
    int d=strlen(m);
    if(d>30||d<=0) return 0;
    for(int i=0; i<d; i++)
    {
        if(m[i]==' '||m[i]=='\r') return 0;
    }
    return 1;
}

int judge3(char m[])//�Ա�Ϸ����ж�
{
    int d=strlen(m);
    if(d==1)
    {
        if(m[0]=='1'||m[0]=='2') return 1;
    }
    return 0;
}
int judge4(char m[])//�꼶�Ϸ����ж�
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
