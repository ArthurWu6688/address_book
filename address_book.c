//
// Created by 93539 on 2023/3/27.
//
#include "address_book.h"

int Welcome() {
    system("cls");
    printf("*************  ͨѶ¼ **************\n");
    printf("*********0.�˳�      1.���*********\n");
    printf("*********2.ɾ��      3.����*********\n");
    printf("*********4.�޸�      5.��ʾ*********\n");
    printf("*********6.���      7.����*********\n");
    printf("************************************\n");
    int input;
    printf("���������ѡ��");
    scanf("%d", &input);
    getchar();//ȡ����󰴻س��Ļ���
    return input;
}

void Init(AddressBook* address_book){
    address_book->contact=(Contact*)malloc(sizeof(Contact)*INIT_CONTACT);
    address_book->size=0;
    address_book->capacity=INIT_CONTACT;
    /*
    strcpy(address_book->contact[address_book->size].name,"����");
    strcpy(address_book->contact[address_book->size].gender,"��");
    address_book->contact[address_book->size].age=20;
    strcpy(address_book->contact[address_book->size].PhoneNum,"13299998888");
    strcpy(address_book->contact[address_book->size].address,"�¿ƴ�");
    ++address_book->size;


    strcpy(address_book->contact[address_book->size].name,"����");
    strcpy(address_book->contact[address_book->size].gender,"Ů");
    address_book->contact[address_book->size].age=18;
    strcpy(address_book->contact[address_book->size].PhoneNum,"14244445555");
    strcpy(address_book->contact[address_book->size].address,"��ҽ");
    ++address_book->size;

    strcpy(address_book->contact[address_book->size].name,"����");
    strcpy(address_book->contact[address_book->size].gender,"��");
    address_book->contact[address_book->size].age=30;
    strcpy(address_book->contact[address_book->size].PhoneNum,"19866667777");
    strcpy(address_book->contact[address_book->size].address,"����Ժ");
    ++address_book->size;
     */
}

void CheckCapacity(AddressBook* address_book){
    //�洢����Ҫ����
    if(address_book->size==address_book->capacity){
        //���������1024�����򷭱���������1024��������������
        int capacity=address_book->capacity>=1024?address_book->capacity+1024*sizeof (Contact):address_book->capacity*sizeof(Contact)*2;
        //��Ϊ�����п��ܻ�ʧ�ܣ�ʧ�ܻ᷵��NULL
        Contact* contact=(Contact*)realloc(address_book->contact,capacity);
        assert(contact!=NULL);//����NULL�ͱ�ʾ����ʧ���ˣ�ʧ���˾��˳�
        address_book->contact=contact;//���ݳɹ��ٸ�ֵ
        address_book->capacity=capacity;//����������
        printf("���ݳɹ���\n");
    }
}

void Insert(AddressBook* address_book){
    CheckCapacity(address_book);
    if(address_book->size==address_book->capacity){
        printf("ͨѶ¼�������޷����������ϵ�ˣ�����س��������У�\n");
        getchar();
        return ;
    }
    //������ϵ��
    printf("��������ϵ��������");
    scanf("%s",address_book->contact[address_book->size].name);//address_book->size������ϵ����������������λ���±�
    printf("��������ϵ���Ա�");
    scanf("%s",address_book->contact[address_book->size].gender);
    printf("��������ϵ�����䣺");
    scanf("%d",&address_book->contact[address_book->size].age);
    printf("��������ϵ�˵绰��");
    scanf("%s",address_book->contact[address_book->size].PhoneNum);
    printf("��������ϵ�˵�ַ��");
    scanf("%s",address_book->contact[address_book->size].address);
    getchar();//���getchar()��Ϊ�˰���������س�����ȡ����
    ++address_book->size;//������ϵ����Ϻ�һ��Ҫ����size��++
    system("cls");
    printf("��ϵ�˱�����ϣ�\n");
    printf("����س��������У�\n");
    getchar();
}

void Display(AddressBook* address_book){
    system("cls");
    printf("%-10s\t%-4s\t%-4s\t%-11s\t%-32s\n","����","�Ա�","����","�绰","��ַ");
    for(int i=0;i<address_book->size;++i){
        printf("%-10s\t%-4s\t%-4d\t%-11s\t%-32s\n"
               ,address_book->contact[i].name
               ,address_book->contact[i].gender
               ,address_book->contact[i].age
               ,address_book->contact[i].PhoneNum
               ,address_book->contact[i].address);
    }
    printf("����س�����!\n");
    getchar();
}

int find_by_name(AddressBook* address_book,char* name){
    int i;
    for(i=0;i<address_book->size;++i){
        if(strcmp(name,address_book->contact[i].name)==0){
            break;
        }
    }
    if(i==address_book->size){
        return -1;//��ʾû�ҵ�
    }
    return i;
}

void Delete(AddressBook* address_book){
    //ͨ��������ɾ����ϵ��
    char name[32]={0};
    printf("������Ҫɾ������ϵ�ˣ�");
    scanf("%s",name);
    getchar();//������Ļس�����ȡ��

    int pos= find_by_name(address_book,name);
    if(pos==-1){
        printf("û���ҵ�Ҫɾ������ϵ�ˣ�����س�������\n");
        getchar();
        return;
    }
    for(int j=pos+1;j<address_book->size;++j){
        address_book->contact[j-1]=address_book->contact[j];
    }
    --address_book->size;
    printf("ɾ����ϵ����ɣ�\n����س���������!\n");
    getchar();//�ȴ�����س�
}

void Find(AddressBook* address_book){
    //ͨ������������ϵ��
    char name[32]={0};
    printf("��������ϵ��������");
    scanf("%s",name);
    getchar();//���������Ļس�����ȡ����

    int pos= find_by_name(address_book,name);
    if(pos==-1){
        printf("û���ҵ�Ҫ���ҵ���ϵ�ˣ�����س��������У�\n");
        getchar();
        return;
    }
    printf("%-10s\t%-4s\t%-4s\t%-11s\t%-32s\n","����","�Ա�","����","�绰","��ַ");
    printf("%-10s\t%-4s\t%-4d\t%-11s\t%-32s\n"
         ,address_book->contact[pos].name
         ,address_book->contact[pos].gender
         ,address_book->contact[pos].age
         ,address_book->contact[pos].PhoneNum
         ,address_book->contact[pos].address);
    printf("����س��������У�\n");
    getchar();
    system("pause");
}

void Update(AddressBook* address_book){
    system("cls");
    //ͨ��������������ϵ��
    char name[32]={0};
    printf("������Ҫ�޸ĵ���ϵ��������");
    scanf("%s",name);
    getchar();

    int pos= find_by_name(address_book,name);
    if(pos==-1){
        printf("û���ҵ�Ҫ���ҵ���ϵ�ˣ�����س��������У�\n");
        getchar();
        system("pause");
        return;
    }

    enum ContactInformation{
        EXIT,
        NAME,
        GENDER,
        AGE,
        PHONENUM,
        ADDRESS,
    };

    while(1){
        printf("************ �޸���ϵ����Ϣ ************\n");
        printf("*******1.����              2.�Ա�******\n");
        printf("*******3.����              4.�绰******\n");
        printf("*******5.��ַ              0.�˳�******\n");
        int input;
        printf("���������ѡ��");
        scanf("%d",&input);
        switch(input){
            case EXIT:
                getchar();
                printf("�޸���ϵ����ɣ�����س�������\n");
                getchar();
                return;
            case NAME:
                printf("��������ϵ��������");
                scanf("%s",address_book->contact[pos].name);
                break;
            case GENDER:
                printf("��������ϵ���Ա�");
                scanf("%s",address_book->contact[pos].gender);
                break;
            case AGE:
                printf("��������ϵ�����䣺");
                scanf("%d",&address_book->contact[pos].age);
                break;
            case PHONENUM:
                printf("��������ϵ�˵绰��");
                scanf("%s",address_book->contact[pos].PhoneNum);
                break;
            case ADDRESS:
                printf("��������ϵ�˵�ַ��");
                scanf("%s",address_book->contact[pos].address);
                break;
            default:
                printf("��������ȷѡ�\n");
                break;
        }
        system("cls");
    }
}

void Clear(AddressBook* address_book){
    address_book->size=0;
    printf("����ͨѶ¼��ɣ�����س�������\n");
    getchar();
}

int cmp_by_name(const void* e1,const void* e2){
    Contact* p1=(Contact*)e1;
    Contact* p2=(Contact*)e2;
    return strcmp(p1->name,p2->name);
}

int cmp_by_gender(const void* e1,const void* e2){
    Contact* p1=(Contact*)e1;
    Contact* p2=(Contact*)e2;
    return strcmp(p1->gender,p2->gender);
}

int cmp_by_age(const void* e1,const void* e2){
    Contact* p1=(Contact*)e1;
    Contact* p2=(Contact*)e2;
    return p1->age-p2->age;
}

int cmp_by_phonenum(const void* e1,const void* e2){
    Contact* p1=(Contact*)e1;
    Contact* p2=(Contact*)e2;
    return strcmp(p1->PhoneNum,p2->PhoneNum);
}

int cmp_by_address(const void* e1,const void* e2){
    Contact* p1=(Contact*)e1;
    Contact* p2=(Contact*)e2;
    return strcmp(p1->address,p2->address);
}

void Sort(AddressBook* address_book){
    system("cls");
    enum ContactInformation{
        EXIT,
        NAME,
        GENDER,
        AGE,
        PHONENUM,
        ADDRESS,
    };
    printf("************ ������ϵ����Ϣ ************\n");
    printf("*******1.����              2.�Ա�******\n");
    printf("*******3.����              4.�绰******\n");
    printf("*******5.��ַ                   ******\n");
    int input;
    printf("������Ҫ����ķ�ʽ��");
    scanf("%d",&input);
    getchar();
    switch(input){
        case NAME:
            qsort(address_book->contact,address_book->size,sizeof(Contact),cmp_by_name);
            Display(address_book);
            break;
        case GENDER:
            qsort(address_book->contact,address_book->size,sizeof(Contact),cmp_by_gender);
            Display(address_book);
            break;
        case AGE:
            qsort(address_book->contact,address_book->size,sizeof(Contact),cmp_by_age);
            Display(address_book);
            break;
        case PHONENUM:
            qsort(address_book->contact,address_book->size,sizeof(Contact),cmp_by_phonenum);
            Display(address_book);
            break;
        case ADDRESS:
            qsort(address_book->contact,address_book->size,sizeof(Contact),cmp_by_address);
            Display(address_book);
            break;
        default:
            printf("��������ȷѡ��!");
            break;
    }
    printf("������ɣ�����س�����\n");
    getchar();
}

void Choice(AddressBook* address_book){
    enum EnumMailList{
        EXIT,
        INSERT,
        DELETE,
        FIND,
        UPDATE,
        DISPLAY,
        CLEAR,
        SORT
    };
    while (1) {

        int choice = Welcome();
        switch (choice) {
            case EXIT:
                printf("��лʹ��ͨѶ¼���ټ���\n");
                Destory(address_book);
                system("pause");
                exit(0);//�˳��������У�����0��return 0��һ����˼
            case INSERT:
                Insert(address_book);
                break;
            case DELETE:
                Delete(address_book);
                break;
            case FIND:
                Find(address_book);
                break;
            case UPDATE:
                Update(address_book);
                break;
            case DISPLAY:
                Display(address_book);
                break;
            case CLEAR:
                Clear(address_book);
                break;
            case SORT:
                Sort(address_book);
                break;
            default:
                system("cls");
                printf("��������ȷѡ��\n");
                break;
        }
    }
}

void Destory(AddressBook* address_book){
    free(address_book->contact);
    address_book->size=0;
    address_book->contact=NULL;
}