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
  service(){}
  void Login()
  {
    string p;
    cout<<"Enter your username :\n"; cin>>Euser.username;
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
     updatereadQuesAnswFile("Answer.txt");
     updatereadQuesAnswFile("Ques_Answ.txt");
    for(int i=0;i<users.size();i++){
      cout<<"username : "<<users[i].username<<"   id : "<<users[i].id<<endl;
    }
  }


  void AskQestions()
  {
    updatereadUserFile("user.txt");
     updatereadQuestionsFile("Ques.txt");
     updatereadQuesAnswFile("Answer.txt");
     updatereadQuesAnswFile("Ques_Answ.txt");
    viewUsers();
    int T;
    string Q;
    cout<<"Enter user id you want to ask: \n";
    cin>>T;
    cin.ignore();
    cout<<"Enter your Question : \n";
    getline(cin,Q);
    Ques QE;  //* object of Ques struct
    QE.from_id=Euser.id;
    QE.to_id=T;
    QE.Q_text=Q;
     Questions.push_back(QE);
    WriteQuestion();
  }
  void Q_from_me()
  {
     updatereadUserFile("user.txt");
     updatereadQuestionsFile("Ques.txt");
     updatereadQuesAnswFile("Answer.txt");
     updatereadQuesAnswFile("Ques_Answ.txt");
    for(int i=0;i<Questions.size();i++)
    {
      if(Questions[i].from_id==Euser.id)
      {
        string s=Questions[i].Q_text;
        cout<<"Question : "<<s<<"  to user id "<<Questions[i].to_id<<endl;
        if(feed.find(s)!=feed.end())
        {
          cout<<"Answer : "<<feed[s]<<endl;
        }
        else{
          cout<<"Unanswered yet\n";
        }
      }
    
    }
  }

  void Q_to_me()
  {

      updatereadUserFile("user.txt");
     updatereadQuestionsFile("Ques.txt");
     updatereadQuesAnswFile("Answer.txt");
     updatereadQuesAnswFile("Ques_Answ.txt");
    int x=0;
    for(int i=0; i<Questions.size();i++)
    {
      x++;
    }

    if(x==0)
    {
      cout<<"Don't have any questions yet\n";
    }
    else
    {
      for(int i=0; i<Questions.size();i++)
      {
        if(Questions[i].to_id==Euser.id)
        {
          cout<<"Question : "<<Questions[i].Q_text<<" from user id "<<Questions[i].from_id<<endl;
          string s=Questions[i].Q_text;
          if(feed.find(s)!=feed.end())
          {
            cout<<" You Answered :"<<feed[s]<<endl;
          }
          else
          {
            cout<<"Not answered yet \n";
          }
        }
      }
    }

  }

void AnswerQuestion()
  {
   
     updatereadUserFile("user.txt");
     updatereadQuestionsFile("Ques.txt");
     updatereadQuesAnswFile("Answer.txt");
     updatereadQuesAnswFile("Ques_Answ.txt");
    for(int i=0;i<Questions.size();i++)
     {
         if(Questions[i].to_id==Euser.id){
        cout<<"Question "<<i+1<<":"<<Questions[i].Q_text<<endl;
        string s=Questions[i].Q_text;
        if(feed.find(s)!=feed.end())
        {
          cout<<"answer :"<<feed[s]<<" by user id :"<<Questions[i].to_id<<endl;
         }
        else{
          cout<<"Not answered yet\n";
          
        }
         }

     }
     //else{
    int num;
    cout<<"Enter the Question number you want to answer :\n";
    cin>>num;
   
    num--;
    ans ob;
    ob.Q=Questions[num].Q_text;
    cout<<"Answer :";
    string Answ;
    cin.ignore();
    getline(cin,Answ);
    ob.A=Answ;

    int p=Questions[num].from_id;
    Ques r;
    r.Q_text=ob.A;
    r.to_id=p;
    r.from_id=Euser.id;

    string Q=Questions[num].Q_text;
    feed[Q]=ob.A;

    answers.push_back(r);
    WriteAnswers();
    QuesWithAns.push_back(ob);
    write_Question_Answers();
  }

    void remove()
  {
     updatereadUserFile("user.txt");
     updatereadQuestionsFile("Ques.txt");
     updatereadQuesAnswFile("Answer.txt");
     updatereadQuesAnswFile("Ques_Answ.txt");
     int number;
     cout<<"select question number you want to remove : \n";
     for(int i=0;i<Questions.size();i++)
     {
      if(Questions[i].from_id==Euser.id)
      {
        cout<<"Question "<<i+1<<":"<<Questions[i].Q_text<<endl;
        string s=Questions[i].Q_text;
        if(feed.find(s)!=feed.end())
        {
          cout<<"answer :"<<feed[s]<<" by user id :"<<Questions[i].to_id<<endl;
        }
        else{
          cout<<"Not answered yet\n";
        }
      }
     }

     cin>>number;
     number--;
     string Qe=Questions[number].Q_text;
     for(int i=0;i<QuesWithAns.size();i++)
     {
      if(QuesWithAns[i].Q==Qe)
      {
        QuesWithAns.erase(QuesWithAns.begin()+1);
      }
     }
     feed.erase(Qe);
     Questions.erase(Questions.begin()+number);
     answers.erase(answers.begin()+number);
     QuesWithAns.erase(QuesWithAns.begin()+number);
     WriteQuestion();
     write_Question_Answers();
     WriteAnswers();
  }


  void MENU()
  {
    cout<<"\n\n***** my systim services *****\n";
    cout<<" \nMENU: ";
    cout<<"\n\n \t1-print question to me";
    cout<<"\n \t2-print question from me";
    cout<<"\n \t3-Answer a question ";
    cout<<"\n \t4-delete question ";
    cout<<"\n \t5-Ask question ";
    cout<<"\n \t6-List system users ";
    cout<<"\n \t7-Logout ";
    cout<<"\n \t8-exit \n";
    cout<<"Enter number in range(1-8) : ";
  }
};
int main()
{
  service myservice;
  int test;

  do
  {
    cout << "Menu\t\t\t" << endl;
    cout << "1-Login \n";
    cout << "2-Sign up \n";
    cout << "Enter number in range (1-2): ";
    cin >> test;

    switch (test)
    {
      case 1:
        myservice.Login();
       // ob1.MENU();
        break;
      case 2:
        myservice.sign_up();
       // ob1.MENU();
        break;
      default:
        cout << "Invalid number... Try again.\n";
        break;
    }

    while (true)
    {
      myservice.MENU();
      cin >> test;

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
          myservice.remove();
          break;
        case 5:
          myservice.AskQestions();
          break;
        case 6:
          myservice.viewUsers();
          break;
        case 7:
          system("cls");
          cout << "Menu:\t\t\t" << endl;
          cout << "1-Login \n";
          cout << "2-sign up \n";
          cout << "Enter number in range (1-2): ";
          cin >> test;
          if (test == 1)
            myservice.Login();
          else if (test == 2)
            myservice.sign_up();
          else
            break;
        //  ob1.MENU();
          break;
        case 8:
          break;
        default:
          cout << "Invalid number... Try again.\n";
          break;
      }

      if (test == 8)
        break;
    }
  } while (test != 8);
}
