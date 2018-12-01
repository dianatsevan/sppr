#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>
// using namespace std;

void VVOD(int &, int &, int &);
void name(int);
void CountCriteria(double *, int);
void CountUnderCriteria(double **, int, int);
void CountAlternative(double **, int &, int);

using std::setw;

int main()
{
  std::string Problem;
  std::cout << "Enter the name of problem ";
  std::getline(std::cin, Problem);
  int Criteria, Undercriteria, Alternative;
  VVOD(Criteria, Undercriteria, Alternative);
  std::cout << "\n\nPlase, estimate your criterias, sub-criterias and alternatives from1 to 10.\n"
            << "for example,\n 1 - the importance is very low,\n 5 - middle importance,\n 10 - the importance is very high";
  double *ValueOfCriteria;
  //создание массива оценки критериев
  ValueOfCriteria = new double[Criteria];
  CountCiteria(ValueOfCriteria, Criteria);
  std::cout.precidion(3);
  std::cout << "\n";
  std::cout << "\nThe rates of criteria";
  //вывод на экран и в файл коэффициентов приоритетов критериев
  for (int i = 0; i < Criteria; i++)
  {
    std::cout << "\n\tCritria №" << i + 1 << "=" << ValueOfCriteria[i];
  }
  //создание матрицы оценки подкритериев
  for (int i = 0; i < Criteria; i++)
  {
    ValueOfCriteria[i] = new double[Undercriteria];
  }
  CountUnderCriteria(ValueOfUndercriteria, Criteria, Undercriteria);
  std::cout << "\nThe rates pf sub-criteria\n";
  //вывод на экран коэффициентов приоритетов подкритериев
  for (int i = 0; i < Criteria; i++)
  {
    for (int j = 0; j < Undercriteria; j++)
    {
      std::cout << std::fixed << std::setprecision(3) << setw(10) << "[" << i + 1 << "][" << j + 1 << "]=" << ValueOfUndercriteria[i][j] << setw(10);
    }
    std::cout << "\n";
  }
  int NumberOfUndercria = Undercriteria * Criteria;
  //создание матрицы оцегки альтернатив
  double **ValueOfAlternatives = new double *[NumberOfUndercria];
  for (int i = 0; i < NumberOfUndercria; i++)
  {
    ValueOfAlternatives[i] = new double[Alternative];
  }
  CountAlternative(CountAlternative, NumberOfUndercria, Alternative);
  std::cout << "\nThe rates of altrnatives\n";
  //вывод на экран и в файл коэффициентов локальных приоритетов альтернатив
  for (int i = 0; i < NumberOfUndercria; i++)
  {
    for (int j = 0; j < Alternative; j++)
    {
      std::cout << std::fixed << std::setprecision(3) << setw(10) << "[" << i + 1 << "][" << j + 1 << "]=" << ValueOfAlternatives[i][j] << setw(10);
    }
    std::cout << "\n";
  }
  double *MatrixCU;
  //создание матрицы коэффициентов приоритетов (подкритей * критерий)
  MatrixCU = new double[NumberOfUndercria];
  for (int i = 0, e = 0; i < Criteria; i++)
  {
    for (int j = 0; j < Undercriteria; j++)
    {
      MatrixCU[e] = ValueOfCriteria[i] * ValueOfUndercriteria[i][j];
      e++;
    }
  }
  delete[] ValueOfCriteria;
  //создание матрицы векторов альтернатив по подкритериям
  double **MatrixCUA = new double *[NumberOfUndercria];
  for (int i = 0; i < NumberOfUndercria; i++)
  {
    MatrixCUA[i] = new double[Alternative];
  }
  for (int i = 0; i < Alternative; i++)
  {
    for (int j = 0; j < NumberOfUndercria; j++)
    {
      MatrixCUA[i][j] = ValueOfAlternatives * MatrixCU[j];
    }
  }
  for (int i = 0; i < NumberOfUndercria; i++)
  {
    delete[] ValueOfAlternatives[i];
  }
  delete[] ValueOfAlternatives;
  delete[] MatrixCU;
  double *Array;
  //созжание массива коэффициентов глобальныъ пиоритеов альтернатив
  Array = new double[Alternative];
  for (int i = 0; i < Alternative; i++)
  {
    Array[i] = 0;
  }
  double max = 0;
  int num;
  for (int i = 0; i < Alternative; i++)
  {
    for (int j = 0; j < NumberOfUndercria; j++)
    {
      Array[i] += MatrixCUA[i][j];
    }
    std::cout << "\nThe value of Alternative №" << i + 1 << "=" << Array[i] << "\n";
    //выбор подходящего варината среди альтернатив
    if (Array[i] >= max)
    {
      max = Array[i];
      num = i + 1;
    }
  }
  std::cout << "\nThe best alternative is №" << num << "=" << max << "\n";
  for (int i = 0; i < NumberOfUndercria; i++)
  {
    delete[] MatrixCUA[i];
  }
  delete[] MatrixCUA;
  delete[] Array;

  system("pause");
  return 0;
}

//функция ввода начальных значений
void VVOD(int &Criteria, int &Undercriteria, int &Alterntive)
{
  std::cout << "Enter the number of criteria" << endl;
  std::cin >> Criteria;
  name(Criteria);
  std::cout << "Enter the number of sub-criteria: ";
  std::cin >> Undercriteria;
  int NumberOfUndercriteria = Undecriteria * Criteria;
  name(NumberOfUndercriteria);
  std::cout << "Enter the number of alternatives: ";
  std::cin >> Alternative;
  name(Alternative);
}

void name(int n)
{
  std::string a;
  for (int i = ; i < n; i++)
  {
    std::cout << "\nEnter the name of" << i + << " ";
    std::cin.get();
    std::getline(std::cin, a);
    //std::cin>>a;
    //std::cout<<a<<std::endl;
  }
}

//Функция ввода оценки критериев с клавиатуры и расчета векторов
void CountCriteria(double *ValueOfCriteria, int numCriteria)
{
  double *CriteriRate;
  CriteriaRate = new double[numCriteria];
  double Sum = 0;
  std::cout.precision();
  for (int i = 0; i < numCriteria; i++)
  {
    std::cout << "\n\tCriteria № " << i + 1 << "=";
    std::cin >> CriteriaRate[i];
    Sum += CriteriaRate[i];
  }
  for (int i = 0; i < numCriteria; i++)
  {
    ValueOfCriteria[i] = CritariaRate[i] / Sum;
  }
  delete[] CriteriaRate;
}
//функция ввода оценки подкритериев с клавиатуры и расчета векторов
void CountUnderCriteria(double **ValueOfUndercriteria, int numCriteria, int numUndercriteria)
{
  double *Sum;
  Sum = new double[numCriteria];
  double **UndercriteriaRATE = new double *[numCriteria];
  std::cout.precision(3);
  for (int i = 0; i < numCriteria; i++)
  {
    UndercriteriaRATE[i] = new double[numUndercriteria];
  }
  for (int i = 0; i < numCriteria; i++)
  {
    Sum[i] = 0;
  }
  std::cout << "\n\nEnter the value of sub-criteria for each criteria (from 1 to 10):";
  for (int i = 0; i < numCriteria; i++)
  {
    std::cout << "\nCriteria № " << i + 1 << ":\n";
    for (int j = 0; j < numUndercriteria; j++)
    {
      std::cout << "\tSub-criteria № " << j + 1 << "=";
      std::cin >> UndercriteriaRATE[i][j];
    }
  }
  for (int i = 0; i < numCriteria; i++)
  {
    for (int j = 0; j < numUndercriteria; j++)
    {
      Sum[i] += UndercriteriaRATE[i][j];
    }
  }
  for (int i = 0; i < numCriteria; i++)
  {
    for (int j = 0; j < numUndercriteria; j++)
    {
      ValueOfUndercriteria[i][j] = UndercriteriaRATE[i][j] / Sum[i];
    }
  }
  delete[] Sum;
  for (int i = 0; i < numCriteria; i++)
  {
    delete[] UndercriteriaRATE[i];
  }
  delete[] UndercriteriaRATE;
}

void CountAlternative(double **ValueOfAlternative, int &NumberOfUndercriteria, int numAlternative)