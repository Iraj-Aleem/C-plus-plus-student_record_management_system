#ifndef STUDENTS_H
#define STUDENTS_H
#include <cstring>
#include<stdio.h>
#include <iostream>
#include <cmath>
#include<fstream>
#include<sstream>
using namespace std;

struct students {
    char name[20];
    float marks[2];
    char StudentRegNumber[100];
    struct students* left;
    struct students* right;
    struct students* parent;
};

	int	count=0;
    struct students* node;
    void createStudent(char* name, char* studentregNumber, float marks[]);
    void addingMark(struct students* root, char* name, int subj_no,float mark);
    void studentsReport(struct students* node,float	marks[]);
    void PrintStudent(struct	students	*node,char	*name);
    void writeList(const struct students* node);
    void	recurInsertStudent(struct	students	*node,struct	students	*newStudent);
    void	readList();
    struct students* root = NULL;
    struct students *Remove(struct students *remove);
    struct	students	*search(struct	students	*node,char	*name);
    void saveList(const struct students* node, std::ofstream& studentList);
    void DeleteStudentRecord(struct students* root, char* name);
	void balanceBinary(struct students *root);
   	void leftRotateBinary(struct students *node);
   	void rightRotateBinary(struct students *node);

    void	createStudent(char	*name,char	*studentregNumber,float	marks[]){
	
	count++;
	struct	students	*newStudent=new	students();
	strcpy(newStudent->name,name);
	strcpy(newStudent->StudentRegNumber,studentregNumber);	
	int	i=0;
	for(i=0;i<	2;i++)
	{
		newStudent->marks[i]=marks[i];
	}
	newStudent->left=NULL;
	newStudent->right=NULL;
	newStudent->parent=NULL;
	
	if(root==NULL){
		root=newStudent;
		newStudent->left=NULL;
		newStudent->right=NULL;
		newStudent->parent=NULL;
		return;
	}
	else{
		recurInsertStudent(root,newStudent);
		return;
	}
}

void	recurInsertStudent(struct	students	*node,struct	students	*newStudent)
{
	if	(strcmp(newStudent->name,node->name)==0){
		cout<<"Name	already	exist"<<endl;
	}
	if	(strcmp(newStudent->name,node->name)>0){
		if(node->right==NULL){
			node->right=newStudent;
			newStudent->parent=node;
			return;
		}
		else{
		recurInsertStudent(node->right,newStudent);
		}
	}
	if	(strcmp(newStudent->name,node->name)<0)
	{
		if(node->left==NULL)
		{
			node->left=newStudent;
			newStudent->parent=node;
			return;
		}
		else{	
		recurInsertStudent(node->left,newStudent);
	}
	}
}
void		addingMark(struct	students	*root,char	*name,int	subj_no,float	mark)
{
	struct	students	*toAddMark=search(root,name);
	if(toAddMark==NULL){
		cout<<"Student	to	add	Mark	is	not	found";
		return;
	}
	toAddMark->marks[subj_no-1]=mark;
	return;
}
	
void	studentsReport(struct	students	*node,float	marks[]){
	if(root==NULL){
		return;
	}

	if(node->left){
		studentsReport(node->left,node->marks);
	}
	cout<<"	\t\t	"<<node->name<<"	\t\t	"<<node->StudentRegNumber<<endl;
	int	j;
	for(j=0;j<2;j++)
	{
		cout<<j+1<<"\n"<<marks[j];
	}
	cout<<"\n";
	if(node->right){
		studentsReport(node->right,node->marks);
	}
}




void	PrintStudent(struct	students	*node,char	*name)
{
int j;
    node = search(root, name);
    if(node != NULL)
    {
        cout<<"Name \tStudent Number \tStudent Marks\n\n";
        cout<<"\n\n"<<node->name<< node->StudentRegNumber;
        for (j = 0; j < 2; j++)
        {
           // std::cout << "\t\t\t\t\t\tMarks[" << j << "] = " << fixed << setprecision(2) << marks[j] << "%%\n\n";
               
			    cout<<j+1<<"\n"<<node->marks[j];
        }
    }
    else{
        cout<<"student not found\n";
    }
}

void writeList(const struct students* node) {
    std::ofstream studentList("studentList.txt");
    saveList(node, studentList);
    studentList.close();
}

void saveList(const struct students* node, std::ofstream& studentList) {
    if (node->left) {
        saveList(node->left, studentList);
    }
    studentList << node->name << " " << node->StudentRegNumber;
    for (int j = 0; j < 2; j++) {
        studentList << " " << node->marks[j];
    }
    studentList << std::endl;
    std::cout << "WRITING Student ***| " << node->name << " |**\n";
    if (node->right) {
        saveList(node->right, studentList);
    }
}

void readFile() {
    std::ifstream studentList("studentList.txt"); // Open file "studentList.txt" for reading
    
    struct students* readStudent = new struct students;
    std::string line;
    while (std::getline(studentList, line)) {
        std::istringstream iss(line);
        iss >> readStudent->name >> readStudent->StudentRegNumber;
        for (int j = 0; j < 2; j++) {
            iss >> readStudent->marks[j];
        }
        
        std::cout << "READING Student ***| " << readStudent->name << " |***\n";
        if (root == NULL) {
            root = readStudent;
            root->left = NULL;
            root->right = NULL;
            root->parent = NULL;
        }
        else {
            readStudent->left = NULL;
            readStudent->right = NULL;
            readStudent->parent = NULL;
        }
        count++;
        recurInsertStudent(root, readStudent);
        PrintStudent(readStudent, readStudent->name);
        
        readStudent = new struct students;
    }
    std::cout << "\t\t\n*** " << root->name << " *** is root\n\n";
    studentList.close();
}


void	DeleteStudent(struct	students	*remove,char	*name){
	remove	=search(root,name);
	struct	students	*var1=NULL;
	struct	students	*var2=NULL;
	struct	students	*var3=NULL;
	
	if(remove->parent){
		struct	students	*Parent	=remove->parent;
		if(Parent->parent){
			var1=Parent->parent;
			if(var1->left==Parent)	var2=var1->left;
			else	var3=var1->right;
		}
		
	if(Parent->left==remove){
		Parent->left=NULL;
		remove->parent=NULL;
		if(var2!=NULL)	var1->left=Parent;
			if(var3!=NULL)	var1->left=Parent;
				return;
	}
}
}
struct	students	*search(struct	students	*node,char	*name)
{

    if (node == NULL) {
        printf("Not found.\n");
        return NULL;
    }

    if (strcmp(name, node->name) < 0) {
        if(node->left){
            return search(node->left, name);
        }
        else{
            return NULL;
        }
    }
    
    if (strcmp(name, node->name) > 0) {
        if(node->right){
            return search(node->right, name);
        }
        else{
            return NULL;
        }
    }

    if (strcmp(name, node->name) == 0){
        return node;
    }
    return node;
    
}
void deleted(struct students *remove, char *name){
    remove = search(root,name); // search the database for name and assign it remove
    struct students *var1 = NULL;
    struct students *var2 =NULL;
    struct students *var3 =NULL;
    
    if(remove->parent){
        // if remove node has a parent
        struct students *Parent = remove->parent;
        if(Parent->parent){
            var1 = Parent->parent;
            if(var1->left == Parent) var2 = var1->left;
                else var3 = var1->right;
                    }
        if(Parent->left == remove){
            Parent->left = NULL;
            remove->parent = NULL;
            if(var2 != NULL) var1->left = Parent;
                if(var3 != NULL) var1->right = Parent;
                    return;
        }
        else{
            Parent->right=NULL;
            remove->parent=NULL;
            struct students *del = Remove(remove);
            if(del != NULL) del->parent=Parent;
                Parent->right = del;
                if(del != NULL){}
            return;
        }
    }
    else{
        struct students *del = Remove(remove);
        root = del;
        return;
    }
}
struct	students	*findMin(struct	students	*node){
	if(node->left==NULL)
		return	node;
	else
		findMin(node->left);
	
	return	NULL;
}

struct students *Remove(struct students *remove){
    count--;
    if(remove->left){
        struct students *anew = findMin(remove->left);
       
        if(anew->left){
            if(anew->parent == remove){
                if (remove->right) remove->right->parent = anew;
                remove->left = NULL;
                anew->right = remove->right; 
                remove->right = NULL;
                anew->parent = NULL;
                delete(remove);
                balanceBinary(anew); // balance binary tree after removal
                return anew;
            }
            else{
                struct students *tmp = anew->left;
                tmp->parent = anew->parent;
                anew->parent->right = tmp;
                remove->right = NULL;
                remove->left = NULL;
                if (anew->right) anew->right->parent = anew;
                if (anew->left) anew->left->parent = anew;
                anew->parent = NULL;
                delete(remove);
                return anew;
            }
        }
        else{
            struct students *tmp = anew->parent;
            if(tmp == remove){
                remove->left = NULL;
                anew->right = remove->right;
                remove->right = NULL;
                anew->parent = NULL;
                delete(remove);
                balanceBinary(anew); 
                return anew;
            }
            else{
                tmp->right  = NULL;
                anew->parent = NULL;
                if(remove->right){ remove->right->parent = anew;}
                remove->left->parent = anew;
                anew->left  = remove->left;
                anew->right = remove->right;
                delete(remove);
                return anew;
            }
        }
    }
    if(remove->right){
        struct students *anew = remove->right;
        remove->right=NULL;
        anew->parent=NULL;
        delete(remove);
        balanceBinary(anew); 
        return anew;
    }
    if(remove->left == NULL && remove->right == NULL){
        delete(remove);
        return NULL;
    }
    return remove;
}

void balanceBinary(struct students *root)
{
    struct students *node;
    int expected, i, oddNodes;
    int numNodes = 0;
    
    node = root;
    
    
    while (node != NULL)
    {
        while(node->left != NULL)
        {
            rightRotateBinary(node);
        }
        node = node->right;
        numNodes++;
    }
    
    
    expected = numNodes - (pow(2,(floor(log2(numNodes+1)))) - 1);
    node = root;

    for(i = 0; i < expected; i++)
    {
        leftRotateBinary(node);
        node = node->right;
    }
    
  
    node = root;
    numNodes = numNodes - expected;
    oddNodes = (numNodes+1)/2;
    while(oddNodes > 1)
    {
        
        leftRotateBinary(root);
        
       
        for(i=0;i<(oddNodes-1);i++)
        {
            leftRotateBinary(node->right);
            node = node->right;
        }
        
   
        oddNodes = (oddNodes+1)/2;
    }
    
}
void rightRotateBinary(struct students *node)
{
    struct students *temp; struct students *original; struct students *left;
    if(node == NULL || node->left == NULL)
    {
        return;
    }
    
    original = node;
    left = original->left;
    
    temp = new	struct students();
    
    strcpy(temp->name, original->name);
    strcpy(temp->StudentRegNumber, original->StudentRegNumber);
    
    strcpy(original->name,left->name);
    strcpy(original->StudentRegNumber, left->StudentRegNumber);
    
    
    temp->left = left->right;
    temp->right = original->right;
    original->left = left->left;
    original->right = temp;
    
   
    delete(left);
}

void leftRotateBinary(struct students *node)
{
    struct students *temp;   struct students *original;   struct students *right;
    
    
    if(node == NULL || node->right == NULL)
    {
        return;
    }
    
    original = node;
    right = original->right;
    temp = new	struct students();
    strcpy(temp->name, original->name);
    strcpy(temp->StudentRegNumber, original->StudentRegNumber);
    strcpy(original->name, right->name);
    strcpy(original->StudentRegNumber, right->StudentRegNumber);
    temp->right = right->left;
    temp->left = original->left;
    original->right = right->right;
    original->left = temp;
    delete(right);
}
#endif

