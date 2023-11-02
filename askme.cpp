#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
 
 using namespace std;
struct User {
    //five members
    string name;
    string username;
    string email;
    string password;
    int id;
};
struct Ques {
    //three members
    string Q_text;
    int to_id;
    int from_id;
};
struct ans {
    //two members
    string Q;
    string A;
};

class Data {
protected:
    vector<User> users;
    vector<Ques> Questions;
    vector<Ques> answers;
    vector<ans> QuesWithAns;
    map<string,string> feed;
public:
    Data() {
        readUserFile("user.txt");
        readQuestionsFile("Ques.txt");
          readAnswersFile("Answer.txt");
         readQuesAnswFile("Ques_Answ.txt");
    }//end of constructor
    void readUserFile(const string& filename) {
        ifstream user_data(filename,ios::in);
        if (!user_data) {
            cerr << "Failed to open " << filename <<endl;
            return;
        }
        User user;
        string line;
        int count = 1;
        while (getline(user_data, line)) {
            switch (count % 5) {
                case 1:
                    user.name = line;
                    break;
                case 2:
                    user.username = line;
                    break;
                case 3:
                    user.email = line;
                    break;
                case 4:
                    user.password = line;
                    break;
                case 0:
                    user.id = stoi(line); //stoi() -> use to convert from string to integer
                    users.push_back(user);
                    break;
            }
            count++;
        }
        user_data.close();
    }
       void updatereadUserFile(const string& filename) {
        ifstream user_data(filename,ios::in);
        if (!user_data) {
            cerr << "Failed to open " << filename <<endl;
            return;
        }
        User user;
        string line;
        int count = 1;
        users.clear();
        while (getline(user_data, line)) {
            switch (count % 5) {
                case 1:
                    user.name = line;
                    break;
                case 2:
                    user.username = line;
                    break;
                case 3:
                    user.email = line;
                    break;
                case 4:
                    user.password = line;
                    break;
                case 0:
                    user.id = stoi(line); //stoi() -> use to convert from string to integer
                    users.push_back(user);
                    break;
            }
            count++;
        }

        user_data.close();
    }
     void readQuestionsFile(const string& filename) {
        ifstream questions_data(filename);
        if (!questions_data) {
            cerr << "Failed to open " << filename << endl;
            return;
        }
        Ques question;
        string line;
        int count = 1;
        while (getline(questions_data, line)) {
            if (count % 3 == 1 && !line.empty()) {
                question.Q_text = line;
                count++;
            } else if (count % 3 == 2 && !line.empty()) {
                question.to_id = stoi(line);
                count++;
            } else if (count % 3 == 0 && !line.empty()) {
                question.from_id = stoi(line);
                Questions.push_back(question);
                count++;
            }
        }
        questions_data.close();
    }
      void updatereadQuestionsFile(const string& filename) {
        ifstream questions_data(filename);
       if (!questions_data) {
            cerr << "Failed to open " << filename << endl;
            return;
        }
        Ques question;
        string line;
        int count = 1;
        Questions.clear();
        while (getline(questions_data, line)) {
            if (count % 3 == 1 && !line.empty()) {
                question.Q_text = line;
                count++;
            } else if (count % 3 == 2 && !line.empty()) {
                question.to_id = stoi(line);
                count++;
            } else if (count % 3 == 0 && !line.empty()) {
                question.from_id = stoi(line);
                Questions.push_back(question);
                count++;
            }
        }
        questions_data.close();
    }
    void readAnswersFile(const string& filename) {
        ifstream answers_data(filename,ios::in);
        if (!answers_data) {
            cerr << "Failed to open " << filename << endl;
            return;
        }
        Ques answer;
        string line;
        int count = 1;
        while (getline(answers_data, line)) {
            if (count % 3 == 1 && !line.empty()) {
                answer.Q_text = line;
                count++;
            } else if (count % 3 == 2 && !line.empty()) {
                answer.to_id = stoi(line);
                count++;
            } else if (count % 3 == 0 && !line.empty()) {
                answer.from_id = stoi(line);
                answers.push_back(answer);
                count++;
            }
        }
        answers_data.close();
    }
   void updatereadAnswersFile(const string& filename) {
        ifstream answers_data(filename,ios::in);
       if (!answers_data) {
            cerr << "Failed to open " << filename << endl;
            return;
        }
        Ques answer;
        string line;
        int count = 1;
        answers.clear();
        while (getline(answers_data, line)) {
            if (count % 3 == 1 && !line.empty()) {
                answer.Q_text = line;
                count++;
            } else if (count % 3 == 2 && !line.empty()) {
                answer.to_id = stoi(line);
                count++;
            } else if (count % 3 == 0 && !line.empty()) {
                answer.from_id = stoi(line);
                answers.push_back(answer);
                count++;
            }
        }
        answers_data.close();
    }
    void readQuesAnswFile(const string& filename) {
        ifstream qa_data(filename,ios::in);
        if (!qa_data) {
            cerr << "Failed to open " << filename <<endl;
            return;
        }
        ans qa;
       string line;
        int count = 1;
        while (getline(qa_data, line)) {
            if (count % 2 == 1 && !line.empty()) {
                qa.Q = line;
                count++;
            } else if (count % 2 == 0 && !line.empty()) {
                qa.A = line;
                count++;
                QuesWithAns.push_back(qa);
                feed[qa.Q] = qa.A;
            }
        }
        qa_data.close();
    }
     void updatereadQuesAnswFile(const string& filename) {
        ifstream qa_data(filename,ios::in);
       if (!qa_data) {
            cerr << "Failed to open " << filename <<endl;
            return;
        }
        ans qa;
          string line;
          int count = 1;
          QuesWithAns.clear();
            while (getline(qa_data, line)) {
            if (count % 2 == 1 && !line.empty()) {
              qa.Q = line;
               count++;
            } 
            else if (count % 2 == 0 && !line.empty()) {
                qa.A = line;
                count++;
                QuesWithAns.push_back(qa);
                feed[qa.Q] = qa.A;
            }
        }
        qa_data.close();
    }
 //=========================== writting ================================//
void write_user_data()
 {
   ofstream UserFile("user.txt");
   for(int i=0; i<users.size(); i++)
   {
    UserFile<<users[i].name<<"\n"<<users[i].username<<"\n"<<users[i].email<<"\n";
    UserFile<<users[i].password<<"\n"<<users[i].id<<"\n";
   }
   UserFile.close();
 }

 void WriteQuestion()
 {
   ofstream QuesFile("Ques.txt");
   for(int i=0;i<Questions.size(); i++)
   {
    QuesFile<<Questions[i].Q_text<<"\n"<<Questions[i].to_id<<"\n"<<Questions[i].from_id<<"\n";
   }
   QuesFile.close();
 }

 void WriteAnswers()
 {
   ofstream AnswerFile("answer.txt");
   for(int i=0; i<answers.size(); i++)
   {
    AnswerFile<<answers[i].Q_text<<"\n"<<answers[i].to_id<<"\n"<<answers[i].from_id<<"\n";
   }
   AnswerFile.close();
 }
 void write_Question_Answers()
 {
    ofstream Q_A("Ques_Answ.txt");
    for(int i=0;i<QuesWithAns.size();i++)
    {
      Q_A<<QuesWithAns[i].Q<<"\n"<<QuesWithAns[i].A<<"\n";
    }
    Q_A.close();
 }

};//end of first class
//===========================================================================================
class service:public Data
{
  protected:
  User Euser;  //* object from User struct

  public:
  service(){ cout<<"******************************************************* Welcom To Askme System *****************************************************************\n";}
  void Login()
  {
     updatereadUserFile("user.txt");
     updatereadQuestionsFile("Ques.txt");
     updatereadAnswersFile("Answer.txt");
     updatereadQuesAnswFile("Ques_Answ.txt");
    string p;
    cout<<"Enter your username :\n"; cin>>Euser.username;
    while(IsUsernameValid())
    {
      cout<<"Please Enter a Correct Username :\n"; cin>>Euser.username;
    }
    cout<<"Enter your password :\n"; cin>> p;
    for(int i=0;i<users.size();i++){
       if(Euser.username==users[i].username){
        Euser.password=users[i].password;
        Euser.name=users[i].name;
        Euser.email=users[i].email;
        Euser.id=users[i].id;
        break;
       }
    }
    while(p!=Euser.password)
    {
       cout<<"uncorrect password...try again "<<endl;
       cin>>p;
    }
  }
  void sign_up()
  {
     updatereadUserFile("user.txt");
     updatereadQuestionsFile("Ques.txt");
     updatereadAnswersFile("Answer.txt");
     updatereadQuesAnswFile("Ques_Answ.txt");
    cin.ignore();
    cout<<"Enter Your name : \n"; getline(cin,Euser.name);// cin>>Euser.name;

    cout<<"Enter Your username : \n"; getline(cin,Euser.username);// cin>>Euser.username;
    while(!IsUsernameValid())
    {
     cout<<"this username already exists..please enter another one : \n";
     cin.ignore();
     getline(cin,Euser.username);
    }
    cout<<"Enter Email : \n";  getline(cin,Euser.email);//cin>>Euser.email;
    while(!IsEmailValid())
    {
     cout<<"unvalid email...please enter a correct email :\n";
      cin.ignore();
     getline(cin,Euser.email);
    }
    cout<<"Enter Password : \n"; getline(cin,Euser.password);// cin>>Euser.password;
       if(users.empty()){
            Euser.id=1;
        }
        else{
        Euser.id = users[users.size()-1].id +1;
        }

    users.push_back(Euser);
    write_user_data();
  }

     bool IsEmailValid() {
    string email=Euser.email;
    size_t atPos = email.find('@');
    size_t dotPos = email.find('.');

    // Check if the '@' and '.' are present and in the correct positions
    if (atPos !=string::npos && dotPos !=string::npos &&atPos < dotPos && dotPos < email.length() - 1) {
        return true;
    }

    return false;
}
 bool IsUsernameValid()
 {
    string user_name=Euser.username;
    for(int i=0;i<users.size();i++)
    {
      if(users[i].username==user_name)
      {
          return false;
      }
    }
    return true;
 }
  void viewUsers()
  { 
    
     updatereadUserFile("user.txt");
     updatereadQuestionsFile("Ques.txt");
     updatereadAnswersFile("Answer.txt");
     updatereadQuesAnswFile("Ques_Answ.txt");
      for(int i=0;i<users.size();i++){
      cout<<"username : "<<users[i].username<<"   id : "<<users[i].id<<endl;
    }
  }
 bool IsIdExist(int id)
 {
    for(int i=0;i<users.size();i++)
    {
        if(users[i].id==id)
        {
            return true;
        }
    }
    return false;
 }

void AskQuestions()
{
     updatereadUserFile("user.txt");
     updatereadQuestionsFile("Ques.txt");
     updatereadAnswersFile("Answer.txt");
     updatereadQuesAnswFile("Ques_Answ.txt");
  viewUsers();
  int T;
  string Q;
  bool found = false;
  cout << "Enter the user ID you want to ask: \n";
  cin >> T;

  while (!found)
  {
    if (T == Euser.id)
    {
      cout << "Sorry, you can't ask yourself. Please enter a different user ID: \n";
      cin >> T;
    }
    else if (!IsIdExist(T))
    {
      cout << "This user is not found. Please enter a valid user ID: \n";
      cin >> T;
    }
    else
    {
      found = true;
    }
  }

  cin.ignore();
  cout << "Enter your question: \n";
  getline(cin, Q);

  Ques QE;  // object of Ques struct
  QE.from_id = Euser.id;
  QE.to_id = T;
  QE.Q_text = Q;
  Questions.push_back(QE);
  WriteQuestion();
}

  void Q_from_me()
{
     updatereadUserFile("user.txt");
     updatereadQuestionsFile("Ques.txt");
     updatereadAnswersFile("Answer.txt");
     updatereadQuesAnswFile("Ques_Answ.txt");

  bool found = false;

  for (int i = 0; i < Questions.size(); i++)
  {
    if (Questions[i].from_id == Euser.id)
    {
      found = true; 

      string s = Questions[i].Q_text;
      cout << "Question from user ID ("<<Questions[i].from_id <<") : "<< s << "  to user ID " << Questions[i].to_id << endl;

      if (feed.find(s) != feed.end())
      {
        cout << "Answer: " << feed[s] << endl;
      }
      else
      {
        cout << "Unanswered yet\n";
      }
    }
  }

  if (!found)
  {
    cout << "There are no questions from you.\n";
  }
}

void Q_to_me()
{
     updatereadUserFile("user.txt");
     updatereadQuestionsFile("Ques.txt");
     updatereadAnswersFile("Answer.txt");
     updatereadQuesAnswFile("Ques_Answ.txt");

  int count = 0; 
  for (int i = 0; i < Questions.size(); i++)
  {
    if (Questions[i].to_id == Euser.id)
    {
      count++; 
      cout << "Question To You : " << Questions[i].Q_text << " from user ID " << Questions[i].from_id << endl;
      string s = Questions[i].Q_text;

      if (feed.find(s) != feed.end())
      {
        cout << "You Answered: " << feed[s] << endl;
      }
      else
      {
        cout << "Not answered yet\n";
      }
    }
  }

  if (count == 0)
  {
    cout << "Don't have any questions yet\n";
  }
}
void AnswerQuestion()
{
     updatereadUserFile("user.txt");
     updatereadQuestionsFile("Ques.txt");
     updatereadAnswersFile("Answer.txt");
     updatereadQuesAnswFile("Ques_Answ.txt");
    bool found = false;
  for (int i = 0; i < Questions.size(); i++)
  {
    if (Questions[i].to_id == Euser.id)
    {
      found = true; 
      cout << "Question ID (" << i + 1 <<") : " << Questions[i].Q_text << endl;
      string s = Questions[i].Q_text;

      if (feed.find(s) != feed.end())
      {
        cout << "Answer: " << feed[s] << "  by user ID: " << Questions[i].to_id << endl;
      }
      else
      {
        cout << "Not answered yet\n";
      }
    }
  }

  if (!found)
  {
    cout << "You don't have any questions.\n";
    return;
  }
  int num;
  cout << "Enter the question ID you want to answer: ";
  cin >> num;
  num--;
  if (num < 0 || num >= Questions.size()||Questions[num].to_id != Euser.id)
  {
    cout << "Invalid question number.\n";
    return;
  }

  string questionText = Questions[num].Q_text;

  if (feed.find(questionText) != feed.end())
  {
    cout << "Do you want to update your answer? (Y/N): ";
    char choice;
    cin >> choice;
    if (choice == 'N' || choice == 'n')
    {
      cout << "Answer not updated.\n";
      return;
    }
  }

  cout << "Answer: ";
  cin.ignore();
  string answer;
  getline(cin, answer);

  feed[questionText] = answer;
  ans ob;
  ob.Q = questionText;
  ob.A = answer;
  QuesWithAns.push_back(ob);
  write_Question_Answers();
  Ques r;
  r.Q_text = answer;
  r.to_id = Questions[num].from_id;
  r.from_id = Euser.id;
  answers.push_back(r);
  WriteAnswers();
  cout << "Answer successfully added.\n";
}

void remove_question()
{
     updatereadUserFile("user.txt");
     updatereadQuestionsFile("Ques.txt");
     updatereadAnswersFile("Answer.txt");
     updatereadQuesAnswFile("Ques_Answ.txt");

  bool found = false; 

  for (int i = 0; i < Questions.size(); i++)
  {
    if (Questions[i].from_id == Euser.id)
    {
      found = true;

      cout << "Question ID (" << i + 1 << ") : " << Questions[i].Q_text << endl;
      string s = Questions[i].Q_text;

      if (feed.find(s) != feed.end())
      {
        cout << "Answer: " << feed[s] << "  by user ID: " << Questions[i].to_id << endl;
      }
      else
      {
        cout << "Not answered yet\n";
      }
    }
  }
  if (!found)
  {
    cout << "You don't have any questions to delete.\n";
    return;
  }

  int number;
  cout << "Enter the question ID you want to remove: ";
  cin >> number;

  number--;

  if (number < 0 || number >= Questions.size() || Questions[number].from_id != Euser.id)
  {
    cout << "Invalid question id or you don't have control to delete this Question. Please try again.\n";
    return;
  }
  string questionText = Questions[number].Q_text;

  for (int i = 0; i < QuesWithAns.size(); i++)
  {
    if (QuesWithAns[i].Q == questionText)
    {
      QuesWithAns.erase(QuesWithAns.begin() + i);
      break;
    }
  }
  feed.erase(questionText);
  Questions.erase(Questions.begin() + number);
  answers.erase(answers.begin() + number);

  WriteQuestion();
  write_Question_Answers();
  WriteAnswers();
  

  cout << "Question have been removed.\n";
}
void remove_answere()
{
  updatereadUserFile("user.txt");
  updatereadQuestionsFile("Ques.txt");
  updatereadAnswersFile("Answer.txt");
  updatereadQuesAnswFile("Ques_Answ.txt");

  bool found = false;

  for (int i = 0; i < Questions.size(); i++)
  {
    if (Questions[i].to_id == Euser.id && feed.find(Questions[i].Q_text) != feed.end())
    {
      found = true; 

      cout << "Question ID (" << i + 1 << ") : " << Questions[i].Q_text << endl;
      cout << "Answer: " << feed[Questions[i].Q_text] << " by user ID: " << Questions[i].to_id << endl;
    }
  }

  if (!found)
  {
    cout << "You haven't answered any questions yet.\n";
    return;
  }

  int questionId;
  cout << "Enter the question ID for which you want to remove the answer: ";
  cin >> questionId;

  questionId--;

  if (questionId < 0 || questionId >= Questions.size() || Questions[questionId].to_id != Euser.id ||
      feed.find(Questions[questionId].Q_text) == feed.end())
  {
    cout << "Invalid question ID or you don't have an answer for this question. Please try again.\n";
    return;
  }

  string questionText = Questions[questionId].Q_text;
   for (int i = 0; i < QuesWithAns.size(); i++)
  {
    if (QuesWithAns[i].Q == questionText)
    {
      QuesWithAns.erase(QuesWithAns.begin() + i);
      break;
    }
  }

  feed.erase(questionText);
  answers.erase(answers.begin() + questionId);
  WriteQuestion();
  write_Question_Answers();
  WriteAnswers();
  cout << "Answer for the question has been removed.\n";
}

void All_feed()
{
  updatereadUserFile("user.txt");
   updatereadQuestionsFile("Ques.txt");
   updatereadAnswersFile("Answer.txt");
   updatereadQuesAnswFile("Ques_Answ.txt");

  for (int i = 0; i < Questions.size(); i++)
  {
      string QuestionText = Questions[i].Q_text;

      if (feed.find(QuestionText) != feed.end())
      {
        cout << "Question ID (" << i + 1 << ") : " << Questions[i].Q_text <<" from user ID ("<<Questions[i].from_id<<")"<< endl;
        cout << "Answer: " << feed[QuestionText] << "  by user ID (" << Questions[i].to_id <<")"<< endl;
      }
  }
}

  void MENU()
  {
    cout<<"************************************* System services *****************************************\n";
    cout<<" \nMENU: ";
    cout<<"\n\n \t1-print question to me ";
    cout<<"\n \t2-print question from me ";
    cout<<"\n \t3-Answer a question or update Answer ";
    cout<<"\n \t4-delete question ";
    cout<<"\n \t5-delete Answer ";
    cout<<"\n \t6-Ask question ";
    cout<<"\n \t7-List system users ";
    cout<<"\n \t8-Feed ";
    cout<<"\n \t9-Logout ";
    cout<<"\n \t10-Exit ";
    cout<<"\nEnter number in range(1-10) : ";
  }
};
int main()
{
  service myservice;
  int test;
  do
  {
    cout << "Menu :\t\t\t"<< endl;
    cout << "\t1-Login \n";
    cout << "\t2-Sign up \n";
    cout <<"\t3-exit \n";
    cout << "Enter number in range (1-3): ";
    in:
    cin >> test;
    switch (test)
    {
      case 1:
        myservice.Login();
        break;
      case 2:
        myservice.sign_up();
        break;
      case 3:
      exit(0);
      default:
        cout << "Invalid number... Try again.\n";
       goto in;
       break;
    }
    while (true)
    {
      myservice.MENU();
      cin >> test;
      cout<<"***********************************************************************************************\n";

      switch (test)
      {
        case 1:
          myservice.Q_to_me();
          break;
        case 2:
          myservice.Q_from_me();
          break;
        case 3:
          myservice.AnswerQuestion();
          break;
        case 4:
          myservice.remove_question();
          break;
        case 5:
          myservice.remove_answere();
          break;
        case 6:
          myservice.AskQuestions();
          break;
        case 7:
           myservice.viewUsers();
           break;
        case 8:
           myservice.All_feed();
           break;
        case 9:
          system("cls");
          cout << "Menu:\t\t\t" << endl;
          cout << "\t1-Login \n";
          cout << "\t2-sign up \n";
          cout<< "\t3-Exit \n";
          cout << "Enter number in range (1-3): ";
          update:
          cin >> test;
          if (test == 1)
          {
            myservice.Login();
            break;
          }
          else if (test == 2)
          {
            myservice.sign_up();
            break;
          }
          else if (test == 3)
          {
            exit(0);
          }
          else
           cout<<"Invalid test number..try again."<<endl;
           goto update;
          break;
        case 10:
        {
          cout <<" Successful To Exit \n";
          exit(0);//break;
        }
        default:
          cout << "Invalid number... Try again.\n";
          break;
      }
      if (test == 10)
        break;
    }
  } while (test != 10);
  return 0;
}
