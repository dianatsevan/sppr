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
  string problem;
  cout << "Enter the name of problem ";
  getline(cin, problem);
  while(!(problem[0] >= 'A' && problem[0] <= 'Z' || problem[0] >= 'a' && problem[0] <= 'z')) {
    cout<<"\nwrong name of problem ";
    getline(cin, problem);
  }

  //ввод основных данных
  int criteriaAmount, subcriteriaAmount, alternativeAmount;
  enterBasicData(criteriaAmount, subcriteriaAmount, alternativeAmount);

  //создание массива оценки критериев
  double* criteriaEstimate;
  criteriaEstimate = new double[criteriaAmount];
  criteriaEvaluation(criteriaEstimate, criteriaAmount);

  //создание матрицы оценки подкритериев
  double** subcriteriaEstimate = new double*[criteriaAmount];
  for(int i = 0; i < criteriaAmount; i++) {
    subcriteriaEstimate[i] = new double[subcriteriaAmount];
  }
  subcriteriaEvaluation(subcriteriaEstimate, criteriaAmount, subcriteriaAmount);

  int allSubcriterias = subcriteriaAmount * criteriaAmount;
  //создание матрицы оценки альтернатив
  double** alternativeEstimate = new double*[allSubcriterias];
  for(int i = 0; i < allSubcriterias; i++) {
    alternativeEstimate[i] = new double[alternativeAmount];
  }
  alternativeEvaluation(alternativeEstimate, allSubcriterias, alternativeAmount);

  //создание матрицы коэффициентов приоритетов (критерий * подкритерий)
  double* priorityFactor;
  priorityFactor = new double[allSubcriterias];

  for(int i = 0, k = 0; i < criteriaAmount; i++) {
    for(int j = 0; j < subcriteriaAmount; j++) {
      priorityFactor[k] = criteriaEstimate[i] * subcriteriaEstimate[i][j];
      k++;
    }
  }
  cout<<"\npriorityFactor\n";
  for(int i = 0; i < allSubcriterias; i++) {
    cout<<i<<" = "<<priorityFactor[i]<<"  ";
  }
  // delete[] criteriaEstimate;

  //создание матрицы векторов альтернатив по подкритериям
  double** alternativeVectors = new double*[allSubcriterias];
  for(int i = 0; i < allSubcriterias; i++) {
    alternativeVectors[i] = new double[alternativeAmount];
  }

  for(int i = 0; i < allSubcriterias; i++){
    for(int j = 0; j < alternativeAmount; j++) {
      alternativeVectors[i][j] = alternativeEstimate[i][j] * priorityFactor[i];
    }
  }
  cout<<"\nalternativeVectors\n";
  for(int i = 0; i < allSubcriterias; i++){
    for(int j = 0; j < alternativeAmount; j++) {
      cout<<setprecision(3)<<setw(10)<<"[" << i + 1 << "][" << j + 1 << "]=" << alternativeVectors[i][j]<<setw(10);
    }
    cout<<"\n";
  }
  // for (int i = 0; i < allSubcriterias; i++)
  // {
  //   delete[] alternativeVectors[i];
  // }
  // delete[] alternativeVectors;
  // delete[] priorityFactor;

  //создание массива коэффициентов глобальных приоритетов альтернатив
  double* globalPriorityFactor;
  globalPriorityFactor = new double[alternativeAmount];
  double max = 0; int num;
  for(int i = 0; i < alternativeAmount; i++) {
    globalPriorityFactor[i] = 0;
    for(int j = 0; j < allSubcriterias; j++) {
      globalPriorityFactor[i] += alternativeVectors[j][i];
      } 
    cout<<"\nThe estimate of Alternative No. "<<i+1<<" = "<<globalPriorityFactor[i];

    if(globalPriorityFactor[i] >= max) {
      max = globalPriorityFactor[i];
      num = i + 1;
    }
  } 

  cout<<"\nThe best alternative is No. "<<num<<" = "<<max<<"\n";
  for(int i = 0; i < allSubcriterias; i++) {
    delete[]alternativeVectors[i];
  }
  delete[]alternativeVectors;
  delete[]globalPriorityFactor;
  

  system("pause");
  return 0;
}

//==============================================================
//функция ввода начальных значений
void enterBasicData(int &criteriaAmount, int &subcriteriaAmount, int &alternativeAmount) {
  
  cout << "Enter the amount of criterias ";
  cin >> criteriaAmount;
  while(1) {
    if(cin.fail()) {
      cin.clear();
      cout<<"wrong value of the criterias amount\n";
      cin.ignore();
      cin>>criteriaAmount;
    }
    if(!cin.fail()) break;
  }
  name(criteriaAmount);
  
  cout << "\nEnter the amount of sub-criterias: ";
  cin >> subcriteriaAmount;
  while(1) {
    if(cin.fail()) {
      cin.clear();
      cout<<"wrong value of the subcriterias amount\n";
      cin.ignore();
      cin>>subcriteriaAmount;
    }
    if(!cin.fail()) break;
  }
    
  for(int i = 1; i <= criteriaAmount; i++) {
    cout<<"\nSub-criterias of criteria "<<i<<"\n";
    name(subcriteriaAmount);
  }

  cout << "\nEnter the amount of alternatives: ";
  cin >> alternativeAmount;    
  while(1) {
    if(cin.fail()) {
      cin.clear();
      cout<<"wrong value of the alternatives amount\n";
      cin.ignore();
      cin>>alternativeAmount;
    }
    if(!cin.fail()) break;
  }

  name(alternativeAmount);
}

void name(int n)
{
  //при вводе одной буквы несколько раз выводи ошибку
  string a;
  for (int i = 1; i <= n; i++)
  {
    cout << "The name of " << i <<" ";
    cin.get();
    getline(cin, a); 
    while(a.length()<2) {
       for(int j = 0; j<=a.length(); j++){
          if(!(a[j] >= 'A' && a[j] <= 'Z' || a[j] >= 'a' && a[j] <= 'z')) {
                cout<<"wrong name of problem\n";
                cin.get();
                getline(cin, a);
                break;
           }
        }
     }
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

    while(1) {
      if(cin.fail()) {
        cin.clear();
        cout<<"\twrong value of the criteria estimate(enter a number)\n";
        cin.ignore();
        cin>>criteriaEstimate[i];
      }
      if(!cin.fail()) {
        if(criteriaEstimate[i] >= 0 && criteriaEstimate[i] <= 10) break;
        else {
          cout<<"\tenter estimate between 0 and 10\n";
          cin.clear();
          cin.ignore();
          cin>>criteriaEstimate[i];
        }
      }
    }

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
      while(1) {
        if(cin.fail()) {
          cin.clear();
          cout<<"\twrong value of the criteria estimate(enter a number)\n";
          cin.ignore();
          cin>>subcriteriaEstimate[i][j];
        }
        if(!cin.fail()) {
          if(subcriteriaEstimate[i][j] >= 0 && subcriteriaEstimate[i][j] <= 10) break;
          else {
            cout<<"\tenter estimate between 0 and 10\n";
            cin.clear();
            cin.ignore();
            cin>>subcriteriaEstimate[i][j];
          }
        }
      }
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
      while(1) {
        if(cin.fail()) {
          cin.clear();
          cout<<"\twrong value of the criteria estimate(enter a number)\n";
          cin.ignore();
          cin>>alternativeEstimate[i][j];
        }
        if(!cin.fail()) {
          if(alternativeEstimate[i][j] >= 0 && alternativeEstimate[i][j] <= 10) break;
          else {
            cout<<"\tenter estimate between 0 and 10\n";
            cin.clear();
            cin.ignore();
            cin>>alternativeEstimate[i][j];
          }
        }
      }
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
