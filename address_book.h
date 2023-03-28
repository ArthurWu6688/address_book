//
// Created by 93539 on 2023/3/27.
//

#ifndef ADDRESS_BOOK_ADDRESS_BOOK_H
#define ADDRESS_BOOK_ADDRESS_BOOK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
//Ϊ�˱�����ϵ����Ϣ������һ����ϵ�˽ṹ��
typedef struct{
    int age;
    char name[32];//��������ͬ���͵����ݷ���һ�𣬼����ڴ����Ĳ�λ
    char gender[8];
    char PhoneNum[16];
    char address[32];
}Contact;

#define INIT_CONTACT 2

typedef struct{
    Contact* contact;//����ħ�����ֵ�ʹ��
    int capacity;//ͨѶ¼������
    int size;//��¼��ǰͨѶ¼����ϵ�˵ĸ�������������ϵ�˵�ʱ��������ϵ�˵�����С��պ���sizeλ��
}AddressBook;

int Welcome();
void Choice(AddressBook* address_book);
void Insert(AddressBook* address_book);
void Init(AddressBook* address_book);
void Display(AddressBook* addressBook);
void Delete(AddressBook* address_book);
void Find(AddressBook* address_book);
void Update(AddressBook* address_book);
void Clear(AddressBook* address_book);
void Sort(AddressBook* address_book);
void CheckCapacity(AddressBook* address_book);

#endif //ADDRESS_BOOK_ADDRESS_BOOK_H
