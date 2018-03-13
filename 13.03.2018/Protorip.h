#define colCount 5
enum type_number { positive, negative, all };
int happy(char*arr);

void sort_u(int*arr, int r);
void sort_d(int*arr, int r);
void sort(int*arr, int r, int n = 1);

int numb(type_number tn, int start = 1, int end = 10);
double numb(type_number tn, double start, int end);

void creat(int*arr, int r, int start, int end, type_number tn);

void creatMatrix(int(*a)[colCount], int r, int start, int end, type_number tn);
void creatMatrix(double(*a)[colCount], int r, double start, int end, type_number tn);

void print_arr(int*arr, int r);
void printMatrix(double(*a)[colCount], int r);
void printMatrix(int(*a)[colCount], int r);\
void creatMatrix(int*a, int coll, int row);
void printMatrix(int*a, int coll, int row);

void arr_d(int*arr, int arr1[][4], int r);

int sum(int num, ...);
void Smooth(int *a, int r, const int *k);
int sum_ind(int(*a)[4], int r, int &col, int &row, int &max);
double sr_arif(double(*a)[colCount], int r);
void creatMatrix(int(*a)[colCount], int r, int start, int end, type_number tn);
void TwoInOne(int(*a)[colCount], int r, int *b);

int FindMax(int* arr, int arrSize, int currPos = 0);

enum typeRait;
char getRait(int *x, typeRait to);
int copyS(char *mas1, char *mas2, int size);
