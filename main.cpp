#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>
using namespace std;

void enterBasicData(int&, int&, int&);
void name(int);
void criteriaEvaluation(double*, int);
void subcriteriaEvaluation(double**, int, int);
void alternativeEvaluation(double**, int, int);

int main() {
  string Problem;
  cout << "Enter the name of problem ";
  getline(cin, Problem);

  int criteriaAmount, subcriteriaAmount, alternativeAmount;
  //ввод основных данных
  enterBasicData(criteriaAmount, subcriteriaAmount, alternativeAmount);

  //создание массива оценки критериев
  double* criteriaEstimate;
  criteriaEstimate = new double[criteriaAmount];
  criteriaEvaluation(criteriaEstimate, criteriaAmount);
  delete[]criteriaEstimate;

  //создание матрицы оценки подкритериев
  double** subcriteriaEstimate = new double*[criteriaAmount];
  for(int i = 0; i < criteriaAmount; i++) {
    subcriteriaEstimate[i] = new double[subcriteriaAmount];
  }
  subcriteriaEvaluation(subcriteriaEstimate, criteriaAmount, subcriteriaAmount);
  
  for(int i = 0; i < criteriaAmount; i++) {
    delete[]subcriteriaEstimate[i];
  }
  delete[]subcriteriaEstimate;


  //
  double** alternativeEstimate = new double*[subcriteriaAmount];
  for(int i = 0; i < alternativeAmount; i++) {
    alternativeEstimate[i] = new double[alternativeAmount];
  }
  int allSubcriterias = subcriteriaAmount * criteriaAmount;
  alternativeEvaluation(alternativeEstimate, allSubcriterias, alternativeAmount);



  system("pause");
  return 0;
}

//==============================================================
//функция ввода начальных значений
void enterBasicData(int &criteriaAmount, int &subcriteriaAmount, int &alternativeAmount) {
  cout << "Enter the amount of criterias ";
  cin >> criteriaAmount;
  name(criteriaAmount);
  cout << "\nEnter the amount of sub-criterias: ";
  cin >> subcriteriaAmount;

  for(int i = 1; i <= criteriaAmount; i++) {
    cout<<"\nSub-criterias of criteria "<<i<<"\n";
    name(subcriteriaAmount);
  }
  cout << "\nEnter the amount of alternatives: ";
  cin >> alternativeAmount;
  name(alternativeAmount);
}

void name(int n)
{
  string a;
  for (int i = 1; i <= n; i++)
  {
    cout << "The name of " << i <<" ";
    cin.get();
    getline(cin, a);
  }
}

//ввод, расчет и вывод оценок критериев
void criteriaEvaluation(double* criteriaEstimate, int criteriaAmount) {
  cout << "\n\nPlase, estimate your criterias, sub-criterias and alternatives from1 to 10.\n"<< "for example,\n 1 - the importance is very low,\n 5 - middle importance,\n 10 - the importance is very high";

  double sum = 0;
  cout.precision(3);

  for(int i = 0; i < criteriaAmount; i++) {
    cout<<"\n\tcriteria No. "<<i+1<<" = ";
    cin>>criteriaEstimate[i];
    sum += criteriaEstimate[i];
  }

  for(int i = 0; i < criteriaAmount; i++) {
    criteriaEstimate[i] = criteriaEstimate[i] / sum;
  }
  
  cout << "\nThe evaluations of criterias";
  for(int i = 0; i < criteriaAmount; i++) {
    cout<< "\n\tCriteria No. " << i + 1 << "=" <<criteriaEstimate[i]<<"  ";
  }
  cout<<endl;
}

//ввод, расчет и вывод оценок подкритериев
void subcriteriaEvaluation(double** subcriteriaEstimate, int criteriaAmount, int subcriteriaAmount) {
  double *sum;
  sum = new double[criteriaAmount];
  for(int i = 0; i < criteriaAmount; i++) {
    sum[i] = 0;
  }
  
  cout<<"\n\nEnter value of subcriteria for each criteria (from 1 to 10):";
  for(int i = 0; i < criteriaAmount; i++) {
    cout<<"\nCriteria No. "<<i + 1;
    for(int j = 0; j < subcriteriaAmount; j++) {
      cout<<"\n\tSubcriteria No. "<<j + 1<<" = ";
      cin>>subcriteriaEstimate[i][j];
    }
  }

  for(int i = 0; i < criteriaAmount; i++) {
    for(int j = 0; j < subcriteriaAmount; j++) {
      sum[i] += subcriteriaEstimate[i][j];
    }
  }

  for(int i = 0; i < criteriaAmount; i++) {
    for(int j = 0; j < subcriteriaAmount; j++) {
      subcriteriaEstimate[i][j] = subcriteriaEstimate[i][j] / sum[i];
    }
  }

  delete[]sum;
  cout<<endl;
  

  for(int i = 0; i < criteriaAmount; i++) {
    for(int j = 0; j < subcriteriaAmount; j++) {
      cout<<setprecision(3)<<setw(5)<<"[" << i + 1 << "][" << j + 1 << "]=" << subcriteriaEstimate[i][j]<<setw(5);
    }
    cout<<"\n";
  }
}

//ввод, расчет и вывод оценок критериев
void alternativeEvaluation(double** alternativeEstimate, int allSubcriterias, int alternativeAmount) {
  cout<<"\n\n\nEnter the value of alternatives for each sub-criteria: \n";

  double* sum;
  sum = new double[allSubcriterias];

  for(int i = 0; i < allSubcriterias; i++) {
    sum[i] = 0;
  }

  for(int i = 0; i < allSubcriterias; i++) {
    cout<<"\nsubcriteria No. "<<i + 1;
    for(int j = 0; j < alternativeAmount; j++) {
      cout<<"\n\talternative No. "<<j + 1<<" = ";
      cin>>alternativeEstimate[i][j];
      sum[i] += alternativeEstimate[i][j];
    }
  }

  for(int i = 0; i < allSubcriterias; i++) {
    for(int j = 0; j < alternativeAmount; j++) {
      alternativeEstimate[i][j] = alternativeEstimate[i][j] / sum[i];
    }
  }

  delete[]sum;

  for(int i = 0; i < allSubcriterias; i++) {
    for(int j = 0; j < alternativeAmount; j++) {
      cout<<setprecision(3)<<setw(5)<<"[" << i + 1 << "][" << j + 1 << "]=" << alternativeEstimate[i][j]<<setw(5);
    }
    cout<<"\n";
  }
}