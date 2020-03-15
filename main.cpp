//Marinica Catalina
//Grupa 212
//Proiect1: Tema7
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Nod
{private:
    int info;
    Nod *prev;
    Nod *next;
public:

    Nod(int info=0){
      this->info=info;
      this->prev=NULL;
      this->next=NULL;
     }

    void set_info(int info)
        {this->info=info;}

    void set_prev(Nod *prev)
        { this->prev=prev; }

	void set_next(Nod *next)
        { this->next=next; }

	int get_info()
        { return this->info; }

	Nod* get_prev()
        { return this->prev; }

	Nod* get_next()
        { return this->next; }

    ~Nod(){
      this->info=0;
      this->prev=NULL;
      this->next=NULL;
    }
};


class DoublyLinkedList
{private:
    Nod* head;
    Nod* tail;
    int  list_size;
 public:

DoublyLinkedList(){
         this->head = NULL;
         this->tail = NULL;
         list_size=0;
         }
void set_list_size(int list_size)
    {this->list_size=list_size;}

void set_head(Nod *head)
    {this->head=head;}

void set_tail(Nod *tail)
    {this->tail=tail;}

int get_list_size()
    {return this->list_size;}

Nod* get_head()
    {return this->head;}

Nod* get_tail()
    {return this->tail;}

void AddElement(int x, int i){
     if(head == NULL && tail == NULL){
        head = new Nod(x);
        tail=head;
        }
     else if(i==1){
                  Nod *p=new Nod(x);
                  p->set_next(head);
                  p->set_prev(NULL);
                  head->set_prev(p);
                  head=p;
                  }
            else{
                Nod *p=new Nod(x);
                Nod *q=new Nod();
                q=head;

                for(int k=1;k<i-1;k++)
                    q=q->get_next();
                if(q->get_next()==NULL){
                    q->set_next(p);
                    p->set_next(NULL);
                    p->set_prev(q);
                    tail=p;
                    }
                else{
                    p->set_next(q->get_next());
                    p->get_next()->set_prev(p);
                    q->set_next(p);
                    p->set_prev(q);
                }
            }
      this->list_size++;
}

friend istream& operator>>(istream& in,DoublyLinkedList& L ){
         int x,i;
         do{
            cout<<"Introduceti pozitia pe care vreti sa introduceti nodul (de la 1 pana la "<<L.get_list_size()+1<<"): ";
            cin>>i;
           }while(i>L.get_list_size()+1 || i<=0);

         cout<<"Introduceti element in lista: ";
         cin>>x;
         L.AddElement(x,i);
         cout<<"Nodul "<<x<<" s-a adaugat pe pozitia "<<i<<endl;
         return in;
        }


friend ostream& operator<<(ostream& out, DoublyLinkedList& L){
             Nod *n = L.head;
             out<<"(head) ";
             while(n){
                out << n->get_info()<<"  ";
                n=n->get_next();
                }
             out<<" (tail)"<<endl<<"(tail) ";
             Nod *p=L.tail;

             while(p){
                out<< p->get_info()<<"  ";
                p=p->get_prev();
                }
             out<<" (head)";
            return out;
        }

void DeleteElement(int i){
    if(head==tail)
        head=tail=NULL;
    else{
         Nod *p=new Nod();
         p=head;
         if(i==1){
            head=head->get_next();
            head->set_prev(NULL);
            delete p;
            }
         else{
            for(int k=1;k<i;k++)
                p=p->get_next();
            if(p->get_next()==NULL){
                tail=p->get_prev();
                p->get_prev()->set_next(NULL);
                }
            else{
                p->get_prev()->set_next( p->get_next() );
                p->get_next()->set_prev( p->get_prev() );
                }
            }
         delete p;
         }
    this->list_size--;
    cout<<"Nodul de pe pozitia "<<i<<" s-a sters cu succes"<<endl;
}



~DoublyLinkedList(){
   while(this->head){
        Nod *p=this->head->get_next();
        delete this->head;
        this->list_size--;
        this->head=p;
        }
  }
};


void Merge(DoublyLinkedList& L1,DoublyLinkedList& L2){
   if(L1.get_head()==NULL) {cout<<L2; return;}
   if(L2.get_head()==NULL) {cout<<L1; return;}

   DoublyLinkedList L;
   int x;

   Nod *current_node=L1.get_head();
   while(current_node!=NULL){
        x=current_node->get_info();
        L.AddElement(x,L.get_list_size()+1);
        current_node=current_node->get_next();
        }
   current_node=L2.get_head();
   while(current_node!=NULL){
        x=current_node->get_info();
        L.AddElement(x,L.get_list_size()+1);
        current_node=current_node->get_next();
        }
   cout<<L;

}

void menu(){
    cout << endl<<"-------- MENIU ---------" << endl
         << "1. Insereaza un element intr-o lista " << endl
         << "2. Sterge un element dintr-o lista"<<endl
         << "3. Afiseaza una dinre liste" << endl
         << "4. Concateneaza 2 liste"<<endl
         << "5. Exit" << endl;
}


int main()
{ int choice,n,i,j;
  DoublyLinkedList *List;
  cout<<"Introduceti cate liste doriti sa aveti:";
  cin>>n;
  List=new DoublyLinkedList[n];


  do
  {
   menu();
   cout << "\nInsereaza actiune: ";
   cin >> choice;
   switch(choice){
    case 1:

           do{
              cout<<"Introduceti nr listei in care inserati( de la 0 pana la "<<n-1<<" ) : ";
              cin>>i;
             } while(i>=n);

           cin>>List[i];
           break;

    case 2:
            do{
              cout<<"Introduceti nr listei din care vreti sa stergeti( de la 0 pana la "<<n-1<<" ) : ";
              cin>>i;
              } while(i>=n);

            if(List[i].get_list_size()!=0)
                {
                    do{
                        cout<<"Introduceti pozitia de pe care vreti sa stergeti nodul (de la 1 pana la "<<List[i].get_list_size()<<"): ";
                        cin>>j;
                      }while(j>List[i].get_list_size() || j<=0);
                    List[i].DeleteElement(j);
                }
            else
                cout<<"Nu se poate sterge niciun element, lista este vida"<<endl;
            break;

    case 3:

           do{
              cout<<"Introduceti nr listei pe care vreti sa o afisati( de la 0 pana la "
                  <<n-1<<" ) : ";
              cin>>i;
             } while(i>=n);

           if(List[i].get_list_size()==0)
                cout<<"Lista este vida"<<endl;
           else
                cout<<List[i];
           break;

    case 4:
        do{
              cout<<"Introduceti prima lista( de la 0 pana la "<<n-1<<" ) : ";
              cin>>i;
          } while(i>=n);
        do{
              cout<<"Introduceti a doua lista( de la 0 pana la "<<n-1<<" ) : ";
              cin>>j;
          } while(j>=n);
            Merge(List[i],List[j]);
            break;
    case 5:
        break;
    default:
            cout<<"Actiune invalida"<<endl;
            break;
       }
  }while(choice!=5);

 return 0;
}
