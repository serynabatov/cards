#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

struct Cards {
	char *last_name;
	char *first_name;
	char *your_fathers_name;
	char *job;
	char *age;
};

typedef struct Cards Cards;

struct Fstrings {
	Cards fstr;
	int number;
	struct Fstrings *next;
};

typedef struct Fstrings Fstrings;

void menu_append ( );
void check_file ( );
void create_file ( );                    
char* the_new_memory ( );
void add_worker ( );
void output_everything ( );               
void delete_someone ( );                 
Fstrings* delete_him ( Fstrings **, char *, char *, char * );
char check_some_shit ( char );
char check_some_shit2 ( );
void push ( Fstrings ***, char *, char *, char *, char *, char * );
void push_next ( Fstrings *, char *, char *, char *, char *, char * );
Fstrings* gets_next ( Fstrings * );
char* create_string ( char *, int, int );
void fill_OLS ( Fstrings ** );
Fstrings* get_him ( Fstrings *, char *, char *, char * );
void rewrite_f ( Fstrings * );
int check_screen ( int, char * );
char input ( );
int check_screen ( int, char * );
int check_screen2 ( int, char * );
void delete_em_all ( );

int main ( )
{
	SetConsoleOutputCP (1251);                 
    SetConsoleCP (1251);
    menu_append ( );
	return 0;
}

void menu_append ( )
{
	char ch = 'a';
	while (1) {
		create_file ( );
		check_file ( );
		puts ("\n1. Добавить сотрудника");
		puts ("2. Вывести всех сотрудников");
		puts ("3. Удалить какого-то сотрудника");
		puts ("4. Завершить работу с картотекой");
		puts ("5. Очистить экран");
		puts ("6. Удалить всех сотрудников\n");
		printf ("Введите номер функции, которую вам нужно исполнить: ");
		ch = check_some_shit2 ( );
		switch (ch) {
		case '1': add_worker ( ); break;
		case '2': output_everything ( ); break;
		case '3': delete_someone ( ); break;
		case '4': exit (1);
		case '5': system ("cls"); break;
		case '6': delete_em_all ( ); break;
		}
	}
}

void check_file ( ) 
{
	FILE *fd;
	long position1;
	fd = fopen ("Card.txt", "rt");
	fseek (fd, 0, SEEK_END);
	position1 = ftell (fd);
	if (position1 == 0L) 
		puts ( "Внимание! Файл пустой! Вам следует его заполнить, для дальнейшей работы с ним, в противном случае вы будете работать с пустым файлом.\n" );
	fclose (fd);
}

void create_file ( )
{
	FILE *f;
	f = fopen ("Card.txt", "at");
	if (f == NULL) puts ("Ошибка при создании файла базы данных");
	else fclose (f);    
}

char* the_new_memory ( )
{
	char s;
	char *string = (char *) malloc ( sizeof (char) );
	int memory = 0;
	do {
		s = getchar( );
		string = (char *) realloc ( string, sizeof (char) * (memory + 2) );
		string [memory] = s;
		memory ++; 
	} while( s != '\n' ) ;
	string [memory - 1] = '\0';
	return string;
}

char check_some_shit (char ch)
{
	ch = input ( );
	while ( ( ch != 'Д' ) && ( ch != 'д' ) && ( ch != 'Н' ) && ( ch != 'н' ) ) {
		printf ("\nВы промахнулись. Введите, пожалуйста, то, что написано выше: ");
	    fflush (stdin);
		ch = input ( );
	    printf ("\n");
    } 
    return ch;
}

char check_some_shit2 ( )
{
	char ch;
	ch = input ( );
	while ( ( ch != '1' ) 
	      && ( ch != '2' ) 
	      && ( ch != '3' ) 
	      && ( ch != '4' ) 
	      && ( ch != '5' ) 
	      && ( ch != '6') ) {
		printf ("\nВы промахнулись. Введите, пожалуйста, то, что написано выше: ");
		fflush (stdin);
		ch = input ( );
		printf ("\n");
	}
	return ch;
}

int check_some_shit3 (int j)
{
	while ( scanf ( "%d", &j ) != 1 ) { 
	    printf("\nВы опечатались, попробуйте снова\n");
	    while ( getchar ( ) != '\n' );
    }
    return j;
}

char input ( )
{
    char *string;
    string = the_new_memory ( );
    while (1) {
    	if ( strlen (string) > 1 ) {
		    printf ("\nВы ввели больше 1 символа. Введите заново: ");
	        free (string);		
		} else {
		    return string [0];
	    }
	    string = the_new_memory ( );
	}
}

void add_worker ( )
{
	FILE *fd;
	Cards worker;
	char ch = 'a';
	printf ( "\nХотите ли вы добавить сотрудника: Да (Д), Нет (Н): " );
	fflush (stdin);
	ch = check_some_shit ( ch );
	if ( ( ch == 'Д' ) || ( ch == 'д' ) )  {
		printf ( "\nВведите фамилию сотрудника: " );
		fflush (stdin);
		worker.last_name = the_new_memory ();
		printf ( "\nВведите имя сотрудника: ");
		fflush (stdin);
		worker.first_name = the_new_memory ();
		printf (" \nВведите отчество: " );
		fflush (stdin);
		worker.your_fathers_name = the_new_memory ();
		printf ("\nВведите возраст сотрудника: ");
		worker.age = the_new_memory ();
		fflush (stdin);
		printf ("\nВведите должность сотрудника: ");
		worker.job = the_new_memory ();
		fflush (stdin);
		fd = fopen ( "Card.txt", "at" );
		if (fd == NULL) {
		    printf ("\nОшибка в получении доступа к базе данных\n");
		} else {
		    fprintf ( fd, "%s %s %s %s %s\n",  worker.last_name, 
		                                       worker.first_name, 
											   worker.your_fathers_name, 
											   worker.age, 
											   worker.job );
	    }
	    free (worker.last_name);
	    free (worker.first_name);
	    free (worker.your_fathers_name);
	    free (worker.age);
	    free (worker.job);
	    fclose (fd);
	} else {
		printf ("\nВы не хотите добавлять сотрудников\n");
	}
	
}

void output_everything ( )
{
	char *buf = NULL;
    int memory = 0;
    int j = 1;
    int ch;
    char ch1 = 'a';
    FILE *f;
    f = fopen ( "Card.txt", "rt" );
    if (f == NULL) puts ("У нас проблемы");
    printf ("\nХотите ли вы вывести всю картотеку сотрудников: Д (Да), Н(Нет): ");  
	ch1 = check_some_shit (ch1);
	printf ("\n");
	if ( ( ch1 == 'Д' ) || ( ch1 == 'д' ) ) {
	    while (1) {
		    ch = fgetc (f);
		    if (ch == EOF) break;
		    if ( ( ch == '\n' ) || ( ch == '\r' ) ) {
			    buf = create_string (buf, memory, '\0');
			    puts (buf) ;
			    memory = 0;
			    j ++;
			    free (buf);
		    }
		    j = check_screen (j, &ch1);
		    if ( ( ch1 == 'Н' ) || ( ch1 == 'н' ) ) {
		    	printf ("\nВы не хотите выводить всю картотеку\n");
				break;
			}
		    buf = create_string (buf, memory, ch);
		    memory ++; 
	    }
    } else {
    	printf ("\nВы не хотите работать с картотекой файлов в режиме чтения\n");
	}
	fclose (f);	
}

int check_screen ( int j, char *ch1 ) 
{
    if ( (j % 20) == 0 ) {
		printf ("\nХотите ли Вы продолжить выводить всю картотеку?: Д (Да), Н(Нет): ");
		*ch1 = check_some_shit (*ch1);
		printf ("\n");
		if ( ( *ch1 != 'Н' ) && ( *ch1 != 'н') ) {
			system ("cls");
			j = 1;
		} 
	}
	return j;
}

void push ( Fstrings ***list, char *c1, char *c2, char *c3, char *c4, char *c5 ) 
{    //создание первого блока
	Fstrings *strings;
	strings = (Fstrings *) malloc ( sizeof (Fstrings) );
	strings->fstr.last_name = _strdup (c1);
	strings->fstr.first_name = _strdup (c2);
	strings->fstr.your_fathers_name = _strdup (c3);
	strings->fstr.age = _strdup (c4);
	strings->fstr.job = _strdup (c5);
	strings->next = (**list);
	(**list) = strings;
}

Fstrings* gets_next (Fstrings *head)
{
	if (head == NULL) return NULL;
	while (head->next) 
		head = head->next;
	return head;
}

void push_next ( Fstrings *list, char *c1, char *c2, char *c3, char *c4, char *c5 )  //добавляет следующий элемент ОЛС
{
	Fstrings *last = gets_next (list);
	Fstrings *temp;
	temp = (Fstrings *) malloc ( sizeof(Fstrings) );
	temp->fstr.last_name = _strdup(c1);
	temp->fstr.first_name = _strdup(c2);
	temp->fstr.your_fathers_name = _strdup(c3);
	temp->fstr.age = _strdup(c4);
	temp->fstr.job = _strdup(c5);
	temp->next = NULL;
	last->next = temp;
}

char* create_string ( char *string, int memory, int s ) 
{
	if (memory == 0) 
		string = (char *) malloc ( sizeof (char) );
	else 
		string = (char *) realloc ( string, sizeof (char) * (memory + 1) );
	*(string + memory) = s;
	return string;
}

void fill_OLS (Fstrings **first) 
{
	char *buf1; 
	char *buf2;
	char *buf3;
	char *buf4;
	char *buf5;                          //строки, которые превращаются в части ОЛС
	FILE *f;
	int memory = 0;
	int iter = 0;                        //проверяет, является ли элемент для ОЛС первым или нет, 1 случай - голова, иначе дальше
	int iter1 = 0;                       //проверяет, какому полю переменной типа Cards присваивать то, что считывается с файла
	int ch;
	buf1 = buf2 = buf3 = buf4 = buf5 = NULL;
	f = fopen("Card.txt", "rt");
	while (1) {
		ch = fgetc (f);
		if (ch == EOF) break;
		if ( ( ch == '\n' ) || ( ch == '\r' ) ) {
			buf5 = create_string (buf5, memory, '\0');
			if (iter == 0) 
				push (&first, buf1, buf2, buf3, buf4, buf5);
			else 
				push_next (*first, buf1, buf2, buf3, buf4, buf5);
			memory = 0;
			iter ++;
			iter1 = 0;
			free (buf1);
			free (buf2);
			free (buf3);
			free (buf4);
			free (buf5);
			ch = fgetc (f);
		}
		if (ch == ' ') {
			switch (iter1) {
			case 0: buf1 = create_string (buf1, memory, '\0'); break;
			case 1: buf2 = create_string (buf2, memory, '\0'); break;
			case 2: buf3 = create_string (buf3, memory, '\0'); break;
			case 3: buf4 = create_string (buf4, memory, '\0'); break;
			}
			iter1 ++;
			if ( iter1 <= 4 ) {
				memory = 0;
			} 
			else {
				buf5 = create_string (buf5, memory, ' ');
				memory ++;     
			}
			ch = fgetc (f);    
		}
		switch (iter1) {
		case 0: buf1 = create_string (buf1, memory, ch); break;
		case 1: buf2 = create_string (buf2, memory, ch); break;
		case 2: buf3 = create_string (buf3, memory, ch); break;
		case 3: buf4 = create_string (buf4, memory, ch); break;
		}
		if ( (buf1 != NULL) && (buf2 != NULL) && (buf3 != NULL) && (buf4 != NULL) )
		    buf5 = create_string (buf5, memory, ch); 
		memory ++;
	}
	fclose (f);
}

void delete_someone ( )
{
	char ch2 = 'a'; 
	Fstrings *list = NULL;
	struct Cards worker;
	fill_OLS ( &list );
	printf("\nХотите ли вы удалить кого-то из сотрудников за невыполнение обязанностей? (Д, Н): ");
	fflush ( stdin );
	ch2 = check_some_shit (ch2);
	if ( ( ch2 == 'Д' ) || ( ch2 == 'д' ) ) {
		printf("\nВведите, пожалуйста, фамилию сотрудника : ");
		fflush ( stdin );
		worker.last_name = the_new_memory ( );
		printf("\nВведите, пожалуйста, имя сотрудника : ");
		fflush ( stdin );
		worker.first_name = the_new_memory ( );
		printf("\nВведите, пожалуйста, отчество сотрудника : ");
		fflush ( stdin );
		worker.your_fathers_name = the_new_memory ( );
		list = delete_him (&list, worker.last_name, worker.first_name, worker.your_fathers_name);
		rewrite_f (list);
        free (worker.last_name);
	    free (worker.first_name);
		free (worker.your_fathers_name);
	} else {
		printf("\nВы не хотите никого увольнять\n");
		fflush (stdin);
	}
}
	
Fstrings* get_him ( Fstrings *list, char *str1, char *str2, char *str3 )
{
	Fstrings *it;
	Fstrings *it1;
	int number = 2;
	int j = 0;
	int quantity = 0;
	char ch1 = 'a';
	it = list;
	it1 = it;
	while (1) {
		if (it == NULL) break; 
		if ( ( strcmp (it->fstr.last_name, str1) == 0 ) 
		  && ( strcmp (it->fstr.first_name, str2) == 0 ) 
		  && ( strcmp (it->fstr.your_fathers_name, str3) == 0 ) ) {
			quantity ++;
			it->number = number - 1;
			printf ("\n%d %s %s %s %s %s\n", it->number, 
			                                 it->fstr.last_name, 
											 it->fstr.first_name, 
										     it->fstr.your_fathers_name, 
											 it->fstr.age, 
											 it->fstr.job );
			number = check_screen2 (number, &ch1);	
			number ++;
 			if ( ( ch1 == 'Н' ) || ( ch1 == 'н' ) ) {
		    	printf ("\nВы не хотите выводить всю картотеку\n");
				break;
			}					 
		} else {
			it->number = 0;
		}
		it = it->next;
	}
	if (quantity >= 2) {
		printf ("\nВы вывели %d одинаковых строк\n", quantity);
		printf ("\nПожалуйста, выберете того, кого хотите уволить, введя соответствующий ему номер: ");
		j = check_some_shit3 (j);
		if ( j > quantity ) {
			while (1) {
				printf ("\nПожалуйста, попробуйте еще раз, вы ввели несуществующий номер: ");
				j = check_some_shit3 (j);
				printf ("\n");
				fflush (stdin);
				if ( j <= quantity ) break;
			}
		}
		printf ("\n");
		while (1) {
			if (it1 == NULL) break;
			if (it1->number == j) break;
			it1 = it1->next;
		}
		fflush (stdin);
	} else if (quantity == 1) {
		printf ("\nВскоре его уволят, подождите несколько секунд\n"); 
		while (1) {
			if (it1 == NULL) break;
			if (it1->number == 1) break;
			it1 = it1->next;
		}
	} else if (quantity == 0) {
		printf ("\nТакого сотрудника нет. Возможно, Вы опечатались. Попробуйте еще раз\n");
		delete_someone ( );
	}
	fflush (stdin);
	free (it);
	return it1;
}

Fstrings* delete_him ( Fstrings **list, char *str1, char *str2, char *str3 )
{
	Fstrings *temp;
	Fstrings *it;
	Fstrings *last;
	temp = *list;
	last = *list;
	it = get_him (*list, str1, str2, str3);
	if (it == NULL) return (NULL);
	if (temp == it) {
		temp = temp->next;
	} else {
		while (temp != it) {
			last = temp;
			temp = temp->next;
		}
		last->next = temp->next;
		temp = *list;
	}
	free (it);
	return (temp);
}

void rewrite_f (Fstrings *list)
{
	FILE *f;
	if (list != NULL) {
		f = fopen ("Card.txt", "wt");
		do {
		    fprintf (f, "%s %s %s %s %s\n", list->fstr.last_name,
		                                    list->fstr.first_name,
		                                    list->fstr.your_fathers_name,
		                                    list->fstr.age,
		                                    list->fstr.job);
		    list = list->next;
		} while (list);
		fflush (f);
		fclose (f);
	} else {
		f = fopen ("Card.txt", "wt");
		fclose (f);
	}
}

int check_screen2 ( int j, char *ch1 ) 
{
    if ( (j % 20) == 0 ) {
		printf ("\nХотите ли Вы продолжить выводить всю картотеку?: Д (Да), Н(Нет): ");
		*ch1 = check_some_shit ( *ch1 );
		printf ("\n");
		if ( ( *ch1 != 'Н' ) && ( *ch1 != 'н') ) {
			system ("cls");
		} 
	}
	return j;
}

void delete_em_all ( )
{
	FILE *f;
	f = fopen ("Card.txt", "wt");
	fclose (f);
}
