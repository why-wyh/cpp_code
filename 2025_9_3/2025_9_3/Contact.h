#define _CRT_SECURE_NO_WARNINGS
#define NAME_MAX 20
#define GENDER_MAX 10
#define TEL_MAX  20
#define ADRESS_MAX 30
typedef struct SeqList Contact;
typedef struct PersonInfo
{
	char name[NAME_MAX];
	char gender[GENDER_MAX];
	int age;
	char tel[TEL_MAX];
	char adress[ADRESS_MAX];
} PeoInfo;

void ContactInit(Contact* ps);

void addContact(Contact* ps);

void delContact(Contact* ps);

void showContact(Contact* ps);

void FindContact(Contact* ps);

void ModifyContact(Contact* ps);

int find_by_name(Contact* ps, char* name);


