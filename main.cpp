// #include <iostream>
// #include <sstream>
// #include <iomanip>
// #include <fstream>
// using namespace std;

// void enterBasicData(int&, int&, int&);
// void name(int);
// void CountCriteria(double *, int);
// void CountUnderCriteria(double **, int, int);
// void CountAlternative(double **, int &, int);

// int main()
// {
//   string Problem;
//   cout << "Enter the name of problem ";
//   getline(cin, Problem);

//   int critAmount, subcritAmount, alterAmount);

//   enterBasicData(critAmount, subcritAmount, alterAmount);

//   cout << "\n\nPlase, estimate your criterias, sub-criterias and alternatives from1 to 10.\n"
//             << "for example,\n 1 - the importance is very low,\n 5 - middle importance,\n 10 - the importance is very high";

//   double *ValueOfCriteria;

//   //создание массива оценки критериев
//   ValueOfCriteria = new double[critAmount];

//   CountCriteria(ValueOfCriteria, critAmount);
//   cout.precision(3);
//   cout << "\n";
//   cout << "\nThe rates of criteria ";
  
//   //вывод на экран и в файл коэффициентов приоритетов критериев
//   for (int i = 0; i < critAmount; i++)
//   {
//     cout << "\n\tCritria No. " << i + 1 << "=" << ValueOfCriteria[i];
//   }

//   //создание матрицы оценки подкритериев
//   double** ValueOfUndercriteria = new double*[critAmount];
//   for (int i = 0; i < critAmount; i++)
//   {
//     ValueOfUndercriteria[i] = new double[Undercriteria];
//   }
//   CountUnderCriteria(ValueOfUndercriteria, critAmount, Undercriteria);
//   cout << "\nThe rates pf sub-criteria\n";

//   //вывод на экран коэффициентов приоритетов подкритериев
//   for (int i = 0; i < critAmount; i++)
//   {
//     for (int j = 0; j < Undercriteria; j++)
//     {
//       cout << fixed << setprecision(3) << setw(10) << "[" << i + 1 << "][" << j + 1 << "]=" << ValueOfUndercriteria[i][j] << setw(10);
//     }
//     cout << "\n";
//   }

//   int NumberOfUndercria = Undercriteria * critAmount;

//   //создание матрицы оцегки альтернатив
//   double **ValueOfAlternatives = new double *[NumberOfUndercria];
//   for (int i = 0; i < NumberOfUndercria; i++)
//   {
//     ValueOfAlternatives[i] = new double[Alternative];
//   }

//   CountAlternative(ValueOfAlternatives, NumberOfUndercria, Alternative);
//   cout << "\nThe rates of altrnatives\n";

//   //вывод на экран и в файл коэффициентов локальных приоритетов альтернатив
//   for (int i = 0; i < NumberOfUndercria; i++)
//   {
//     for (int j = 0; j < Alternative; j++)
//     {
//       cout << fixed << setprecision(3) << setw(10) << "[" << i + 1 << "][" << j + 1 << "]=" << ValueOfAlternatives[i][j] << setw(10);
//     }
//     cout << "\n";
//   }

//   double *MatrixCU;

//   //создание матрицы коэффициентов приоритетов (подкритей * критерий)
//   MatrixCU = new double[NumberOfUndercria];

//   for (int i = 0, e = 0; i < critAmount; i++)
//   {
//     for (int j = 0; j < Undercriteria; j++)
//     {
//       MatrixCU[e] = ValueOfCriteria[i] * ValueOfUndercriteria[i][j];
//       e++;
//     }
//   }
//   delete[] ValueOfCriteria;

//   //создание матрицы векторов альтернатив по подкритериям
//   double **MatrixCUA = new double *[NumberOfUndercria];

//   for (int i = 0; i < NumberOfUndercria; i++)
//   {
//     MatrixCUA[i] = new double[Alternative];
//   }

//   for (int i = 0; i < Alternative; i++)
//   {
//     for (int j = 0; j < NumberOfUndercria; j++)
//     {
//       MatrixCUA[i][j] = ValueOfAlternatives[j][i] * MatrixCU[j];
//     }
//   }

//   for (int i = 0; i < NumberOfUndercria; i++)
//   {
//     delete[] ValueOfAlternatives[i];
//   }
//   delete[] ValueOfAlternatives;
//   delete[] MatrixCU;

//   double *Array;

//   //созжание массива коэффициентов глобальныъ пиоритеов альтернатив
//   Array = new double[Alternative];

//   for (int i = 0; i < Alternative; i++)
//   {
//     Array[i] = 0;
//   }
  
//   double max = 0;
//   int num;

//   for (int i = 0; i < Alternative; i++)
//   {
//     for (int j = 0; j < NumberOfUndercria; j++)
//     {
//       Array[i] += MatrixCUA[i][j];
//     }
//     cout << "\nThe value of Alternative No. " << i + 1 << "=" << Array[i] << "\n";

//     //выбор подходящего варината среди альтернатив
//     if (Array[i] >= max)
//     {
//       max = Array[i];
//       num = i + 1;
//     }
//   }

//   cout << "\nThe best alternative is No. " << num << "=" << max << "\n";
//   for (int i = 0; i < NumberOfUndercria; i++)
//   {
//     delete[] MatrixCUA[i];
//   }
//   delete[] MatrixCUA;
//   delete[] Array;

//   system("pause");
//   return 0;
// }

// //функция ввода начальных значений
// void enterBasicData(int &critAmount, int &subcritAmount, int &alterAmount) {
//   cout << "Enter the amount of criterias ";
//   cin >> critAmount;
//   name(critAmount);
//   cout << "\nEnter the amount of sub-criterias: ";
//   cin >> subcritAmount;

//   for(int i = 1; i <= critAmount; i++) {
//     cout<<"\nSub-criterias of criteria "<<i<<"\n";
//     name(subcritAmount);
//   }
//   cout << "\nEnter the amount of alternatives: ";
//   cin >> alterAmount;
//   name(alterAmount);
// }

// void name(int n)
// {
//   string a;
//   for (int i = 1; i <= n; i++)
//   {
//     cout << "The name of " << i <<" ";
//     cin.get();
//     getline(cin, a);
//   }
// }

// //Функция ввода оценки критериев с клавиатуры и расчета векторов
// void CountCriteria(double *ValueOfCriteria, int numCriteria)
// {
//   double *CriteriaRate;
//   CriteriaRate = new double[numCriteria];
//   double Sum = 0;
//   cout.precision(3);

//   for (int i = 0; i < numCriteria; i++)
//   {
//     cout << "\n\tCriteria No. " << i + 1 << "=";
//     cin >> CriteriaRate[i];
//     Sum += CriteriaRate[i];
//   }

//   for (int i = 0; i < numCriteria; i++)
//   {
//     ValueOfCriteria[i] = CriteriaRate[i] / Sum;
//   }
//   delete[] CriteriaRate;
// }

// //функция ввода оценки подкритериев с клавиатуры и расчета векторов
// void CountUnderCriteria(double **ValueOfUndercriteria, int numCriteria, int numUndercriteria)
// {
//   double *Sum;
//   Sum = new double[numCriteria];
//   double **UndercriteriaRATE = new double *[numCriteria];
//   cout.precision(3);

//   for (int i = 0; i < numCriteria; i++)
//   {
//     UndercriteriaRATE[i] = new double[numUndercriteria];
//   }

//   for (int i = 0; i < numCriteria; i++)
//   {
//     Sum[i] = 0;
//   }

//   cout << "\n\nEnter the value of sub-criteria for each criteria (from 1 to 10):";
//   for (int i = 0; i < numCriteria; i++)
//   {
//     cout << "\nCriteria No. " << i + 1 << ":\n";
//     for (int j = 0; j < numUndercriteria; j++)
//     {
//       cout << "\tSub-criteria No. " << j + 1 << "=";
//       cin >> UndercriteriaRATE[i][j];
//     }
//   }

//   for (int i = 0; i < numCriteria; i++)
//   {
//     for (int j = 0; j < numUndercriteria; j++)
//     {
//       Sum[i] += UndercriteriaRATE[i][j];
//     }
//   }

//   for (int i = 0; i < numCriteria; i++)
//   {
//     for (int j = 0; j < numUndercriteria; j++)
//     {
//       ValueOfUndercriteria[i][j] = UndercriteriaRATE[i][j] / Sum[i];
//     }
//   }
//   delete[] Sum;

//   for (int i = 0; i < numCriteria; i++)
//   {
//     delete[] UndercriteriaRATE[i];
//   }
//   delete[] UndercriteriaRATE;
// }

// //функция ввода оценки альтернатив с клавиатуры и расеты векторов
// void CountAlternative(double **ValueOfAlternative, int &NumberOfUndercriteria, int numAlternative){
//   cout.precision(4);
//   cout<<"\n\n\nEnter the value of alternatives for each sub-criteria: \n";

//   double* Sum;
//   Sum = new double[NumberOfUndercriteria];

//   for(int i = 0; i < NumberOfUndercriteria; i++) {
//     Sum[i] = 0;
//   }

//   double** AlternativeRate = new double*[numAlternative];

//   for(int i =0; i < NumberOfUndercriteria; i++) {
//     cout<<"\nsub-criteria No. "<<i + 1<<":\n";

//     for(int j =0; j < numAlternative; j++) {
//       cout<<"\tAlternative No. "<<j + 1<<"=";
//       cin>>AlternativeRate[i][j];
//       Sum[i] += AlternativeRate[i][j];
//     }
//   }

//   for(int i =0; i < NumberOfUndercriteria; i++) {
//     for(int j = 0; j < numAlternative; j++){
//       ValueOfAlternative[i][j] = AlternativeRate[i][j] / Sum[i];
//     }
//   }
//   delete[]Sum;

//   for(int i =0; i < NumberOfUndercriteria; i++) {
//     delete[]AlternativeRate[i];
//   }
//   delete[]AlternativeRate;
// }