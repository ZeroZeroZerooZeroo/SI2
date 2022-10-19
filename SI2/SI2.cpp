#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <math.h>

struct money {
	int income1;
	int income2;
	int expenses;
};
struct phone {
	char* name_phone;
	int price_phone;
	char* cover_color;
};
struct car {
	char* color;
	int price_car;
	char* brand;
};
struct house {
	int area;
	int price_home;
};
struct computer {
	int computer_price;
	char* body_color;
	char* gaming;
};
struct business_calculator {
	money your_money;
	phone your_phone;
	car your_car;
	house your_house;
	computer your_computer;
};
void initialization(struct business_calculator* a);
void conclusion(struct business_calculator* a);
void input(struct business_calculator* a);
void total_income(struct business_calculator a);
void total_price(struct business_calculator a);
void work(struct business_calculator a);
int main()
{
	setlocale(LC_ALL, "Rus");
	struct business_calculator your_bс;
	int funct = 0;
	initialization(&your_bс);
	input(&your_bс);
	conclusion(&your_bс);
	while (funct != 5) {
		printf("\nНажмите:\n1 - для вывода чек листа\n2 - для подсчета общего дохода\n3 - для подсчета общего времени работы,чтобы накопить \n4 - для подсчета общей стоимости вещей\n5 - выхода\n");
		scanf("%d", &funct);
		switch (funct) {
		case 1:
			conclusion(&your_bс);
			break;
		case 2:
			total_income(your_bс);
			break;
		case 3:
			work(your_bс);
			break;
		case 4:
			total_price(your_bс);
			break;
		}
	}
}
void initialization(struct business_calculator* a) {
	a->your_money.income1 = 0;
	a->your_money.income2 = 0;
	a->your_money.expenses = 0;
	a->your_phone.name_phone = (char*)calloc(20, (sizeof(char)));
	a->your_phone.cover_color = (char*)calloc(20, (sizeof(char)));
	a->your_phone.price_phone = 0;
	a->your_car.color = (char*)calloc(20, (sizeof(char)));
	a->your_car.price_car = 0;
	a->your_car.brand = (char*)calloc(20, (sizeof(char)));
	a->your_house.area = 0;
	a->your_house.price_home = 0;
	a->your_computer.computer_price = 0;
	a->your_computer.body_color = (char*)calloc(20, (sizeof(char)));
	a->your_computer.gaming = (char*)calloc(20, (sizeof(char)));
}
void conclusion(struct business_calculator* a) {
	printf("Ваш доход 1 за месяц- %d, Ваш доход 2 за месяц - %d, Ваш расход за месяц - %d\n", a->your_money.income1, a->your_money.income2, a->your_money.expenses);
	printf("Марка телефона - %s, Цвет чехла телефона - %s,Цена телефона - %d\n", a->your_phone.name_phone, a->your_phone.cover_color, a->your_phone.price_phone);
	printf("Цвет машины - %s, Цена машины - %d, Марка машины - %s\n", a->your_car.color, a->your_car.price_car, a->your_car.brand);
	printf("Площадь дома - %d, Цена дома - %d\n", a->your_house.area, a->your_house.price_home);
	printf("Цена компьютера - %d, Цвет корпуса компьютера - %s, Ваш компьютер игровой? - %s\n", a->your_computer.computer_price, a->your_computer.body_color, a->your_computer.gaming);
}
void input(struct business_calculator* a) {
	setlocale(LC_ALL, "Rus");
	printf("\nВведите ваш доход 1 за месяц: ");
	scanf("%d", &a->your_money.income1);
	printf("\nВведите ваш доход 2: за месяц ");
	scanf("%d", &a->your_money.income2);
	printf("\nВведите ваш расход за месяц: ");
	scanf("%d", &a->your_money.expenses);

	printf("\nВведите марку телефона ");
	scanf("%s", a->your_phone.name_phone);
	printf("\nВведите цвет чехла ");
	scanf("%s", a->your_phone.cover_color);
	printf("\nВведите цену телефона ");
	scanf("%d", &a->your_phone.price_phone);

	printf("\nВведите цвет машины ");
	scanf("%s", a->your_car.color);
	printf("\nВведите цену машины ");
	scanf("%d", &a->your_car.price_car);
	printf("\nВведите марку машины ");
	scanf("%s", a->your_car.brand);

	printf("\nВведите площадь дома(кв.м.) ");
	scanf("%d", &a->your_house.area);
	printf("\nВведите цену дома ");
	scanf("%d", &a->your_house.price_home);

	printf("\nВведите цену компьютера ");
	scanf("%d", &a->your_computer.computer_price);
	printf("\nВведите цвет корпуса компьютера ");
	scanf("%s", a->your_computer.body_color);
	printf("\nВаш компьютер игровой? ");
	scanf("%s", a->your_computer.gaming);
	while (getchar() != '\n');
}

void total_income(struct business_calculator a) {
	int sum=0;
	sum = a.your_money.income1 + a.your_money.income2 - a.your_money.expenses;
	printf("Ваш общий доход - %d", sum);
}

void total_price(struct business_calculator a) {
	int prise = 0;
	prise = a.your_car.price_car + a.your_computer.computer_price + a.your_house.price_home + a.your_phone.price_phone;
	printf("Цена всех вещей - %d", prise);
}

void work(struct business_calculator a) {
	int sum1 = 0,prise1=0,itg=0;
	sum1 = a.your_money.income1 + a.your_money.income2 - a.your_money.expenses;
	prise1 = a.your_car.price_car + a.your_computer.computer_price + a.your_house.price_home + a.your_phone.price_phone;
	itg = prise1 / sum1;
	if (sum1 == 0||sum1 < 0) {
		printf("Вы не сможете накопить на эти вещи. Вам надо увеличить доходы или уменьшить расходы,потому что ваш общий доход равен 0 или ваши доходы меньше расходов");
	}
	else
		printf("Вам нужно работать примерно %d месяцев,чтобы накопить на эти вещи", itg);
}

