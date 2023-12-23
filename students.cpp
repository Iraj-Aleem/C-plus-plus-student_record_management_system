//#include <iostream>
//using	namespace	std;
//#include	"students.h"
//
//
//struct	students	students::createStudent(char	*name,char	*studentregNumber,float	marks[]){
//	count++;
//	struct	students	*newStudent=new	students();
//	strcpy(newStudent->name,name);
//	strcpy(newStudent->StudentRegNumber,studentregNumber);	
//	int	i=0;
//	for(i=0;i<	2;i++)
//	{
//		newStudent->marks[i]=marks[i];
//	}
//	newStudent->left=NULL;
//	newStudent->right=NULL;
//	newStudent->parent=NULL;
//	
//	if(root==NULL){
//		root=newStudent;
//		newStudent->left=NULL;
//		newStudent->right=NULL;
//		newStudent->parent=NULL;
//		return;
//	}
//	else{
//		recurInsertStudent(root,newStudent);
//		return;
//	}
//	return 0; 
//}
//
//void	students::	recurInsertStudent(struct	students	*node,struct	students	*newStudent)
//{
//	if	(strcmp(newStudent->name,node->name)==0){
//		cout<<"Name	already	exist"<<endl;
//	}
//	if	(strcmp(newStudent->name,node->name)>0){
//		if(node->right==NULL){
//			node->right=newStudent;
//			newStudent->parent=node;
//			return;
//		}
//		else{
//		recurInsertStudent(node->right,newStudent);
//		}
//	}
//	if	(strcmp(newStudent->name,node->name)<0)
//	{
//		if(node->left==NULL)
//		{
//			node->left=newStudent;
//			newStudent->parent=node;
//			return;
//		}
//		else{	
//		recurInsertStudent(node->left,newStudent);
//	}
//	}
//}
//void		addingMark(struct	students	*root,char	*name,int	subj_no,float	mark)
//{
//	struct	students	*toAddMark=search(root,name);
//	if(toAddMark==NULL){
//		cout<<"Student	to	add	Mark	is	not	found";
//		return;
//	}
//	toAddMark->marks[subj_no-1]=mark;
//	return;
//}
//	
////void	balanceBinary(root);
////void	studentsReport(struct	student	*node);
//void	students::	PrintStudent(struct	students	*node,char	*name)
//{
//int j;
//    node = search(root, name);
//    if(node != NULL)
//    {
//        cout<<"Name \tStudent Number \tStudent Marks\n\n";
//        cout<<"\n\n"<<node->name<< node->studentNumber;
//        for (j = 0; j < 2; j++)
//        {
//            std::cout << "\t\t\t\t\t\tMarks[" << j << "] = " << std::fixed << std::setprecision(2) << marks[j] << "%%\n\n";
//                   j+1, node->marks[j];
//        }
//    }
//    else{
//        cout<<"student not found\n";
//    }
//}
//
//void	writeFile(const	struct	students	*node){
//}
//void	readFile(void){
//}
//void	saveList(const	struct	students	*node,FILE	*list){
//}
//
//struct	student		*DeleteStudent(struct	students	*remove,char	*name){
//	remove	=search(root,name);
//	struct	students	*var1=NULL;
//	struct	students	*var2=NULL;
//	struct	students	*var3=NULL;
//	
//	if(remove->parent){
//		struct	students	*Parent	=remove->parent;
//		if(Parent->parent){
//			var1=Parent->parent;
//			if(var1->left==Parent)	var2=var1->left;
//			else	var3=var1->right;
//		}
//		}
//	if(Parent->left==remove){
//		Parent->left=NULL;
//		remove->parent=NULL;
//		if(var2!=NULL)	var1->left=Parent;
//	}
//}
//
//struct	students	students::*search(struct	students	*node,char	*name){
//
//    if (node == NULL) {
//        printf("Not found.\n");
//        return NULL;
//    }
//    //if strcmp result < 0 we search for the tudent in left child
//    if (strcmp(name, node->name) < 0) {
//        if(node->left){
//            return search(node->left, name);
//        }
//        else{
//            return NULL;
//        }
//    }
//    //if strcmp result > 0 we search for the student in right
//    if (strcmp(name, node->name) > 0) {
//        if(node->right){
//            return search(node->right, name);
//        }
//        else{
//            return NULL;
//        }
//    }
//    //if strcmp result == 0 return node
//    if (strcmp(name, node->name) == 0){
//        return node;
//    }
//    return node;
//    
//}
//void students::deleted(struct students *remove, char *name){
//    remove = search(root,name); // search the database for name and assign it remove
//    struct students *var1 = NULL;
//    struct students *var2 =NULL;
//    struct students *var3 =NULL;
//    
//    if(remove->parent){
//        // if remove node has a parent
//        struct students *Parent = remove->parent;
//        if(Parent->parent){
//            var1 = Parent->parent;
//            if(var1->left == Parent) var2 = var1->left;
//                else var3 = var1->right;
//                    }
//        if(Parent->left == remove){
//            Parent->left = NULL;
//            remove->parent = NULL;
//            if(var2 != NULL) var1->left = Parent;
//                if(var3 != NULL) var1->right = Parent;
//                    return;
//        }
//        else{
//            Parent->right=NULL;
//            remove->parent=NULL;
//            struct students *del = Remove(remove);
//            if(del != NULL) del->parent=Parent;
//                Parent->right = del;
//                if(del != NULL){}
//            return;
//        }
//    }
//    else{
//        struct students *del = Remove(remove);
//        root = del;
//        return;
//    }
//}
//
////delete a student and balance its subtrees
//struct students	students:: *Remove(struct students *remove){
//    count--;
//    if(remove->left){
//        struct students *new = findMin(remove->left);
//        // Get the findMin: (smallest in the left subtree)
//        if(new->left){
//            if(new->parent == remove){
//                if (remove->right) remove->right->parent = new;
//                remove->left = NULL;
//                new->right = remove->right;  //Copy the remove content to this new node
//                remove->right = NULL;
//                new->parent = NULL;
//                free(remove);
//                balanceBinary(new); // balance binary tree after removal
//                return new;
//            }
//            else{
//                struct students *tmp = new->left;
//                tmp->parent = new->parent;
//                new->parent->right = tmp;
//                remove->right = NULL;
//                remove->left = NULL;
//                if (new->right) new->right->parent = new;
//                if (new->left) new->left->parent = new;
//                new->parent = NULL;
//                free(remove);
//                return new;
//            }
//        }
//        else{
//            struct students *tmp = new->parent;
//            if(tmp == remove){
//                remove->left = NULL;
//                new->right = remove->right;
//                remove->right = NULL;
//                new->parent = NULL;
//                free(remove);
//                balanceBinary(new); // balance binary tree after removal
//                return new;
//            }
//            else{
//                tmp->right  = NULL;
//                new->parent = NULL;
//                if(remove->right){ remove->right->parent = new;}
//                remove->left->parent = new;
//                new->left  = remove->left;
//                new->right = remove->right;
//                free(remove); // derefrence 'remove'
//                return new;
//            }
//        }
//    }
//    if(remove->right){
//        struct students *new = remove->right;
//        remove->right=NULL;
//        new->parent=NULL;
//        free(remove);
//        balanceBinary(new); // balances binary tree after removal
//        return new;
//    }
//    if(remove->left == NULL && remove->right == NULL){
//        free(remove);
//        return NULL;
//    }
//    return remove;
//}
//
//
//	
//}
////#include <iostream>
////#include <cstring>
////#include <iomanip>
////#include "students.h"
////
////void students::createStudent(char* name, char* studentregNumber, float marks[]) {
////    count++;
////    struct student* newStudent = new student();
////    strcpy(newStudent->name, name);
////    strcpy(newStudent->StudentRegNumber, studentregNumber);
////    int i = 0;
////    for (i = 0; i < 2; i++) {
////        newStudent->marks[i] = marks[i];
////    }
////    newStudent->left = NULL;
////    newStudent->right = NULL;
////    newStudent->parent = NULL;
////
////    if (root == NULL) {
////        root = newStudent;
////        return;
////    }
////    else {
////        recurInsertStudent(root, newStudent);
////        return;
////    }
////}
////
////void students::recurInsertStudent(struct student* node, struct student* newStudent) {
////    if (strcmp(newStudent->name, node->name) == 0) {
////        cout << "Name already exists" << endl;
////        return;
////    }
////    if (strcmp(newStudent->name, node->name) > 0) {
////        if (node->right == NULL) {
////            node->right = newStudent;
////            newStudent->parent = node;
////            return;
////        }
////        else {
////            recurInsertStudent(node->right, newStudent);
////        }
////    }
////    if (strcmp(newStudent->name, node->name) < 0) {
////        if (node->left == NULL) {
////            node->left = newStudent;
////            newStudent->parent = node;
////            return;
////        }
////        else {
////            recurInsertStudent(node->left, newStudent);
////        }
////    }
////}
////
////void students::addingMark(struct student* root, char* name, int subj_no, int mark) {
////    struct student* toAddMark = search(root, name);
////    if (toAddMark == NULL) {
////        cout << "Student to add Mark is not found";
////        return;
////    }
////    toAddMark->marks[subj_no - 1] = mark;
////    return;
////}
////
////void students::PrintStudent(struct student* node, char* name) {
////    node = search(root, name);
////    if (node != NULL) {
////        cout << "Name \tStudent Number \tStudent Marks\n\n";
////        cout << "\n\n" << node->name << node->StudentRegNumber;
////        for (int j = 0; j < 2; j++) {
////            cout << "\t\t\t\t\t\tMarks[" << j + 1 << "] = " << fixed << setprecision(2) << node->marks[j] << "%%\n\n";
////        }
////    }
////    else {
////        cout << "Student not found\n";
////    }
////}
////
////void students::writeFile(const struct student* node) {
////    // Implementation of writing the student records to a file
////    // ...
////}
////
////void students::readFile() {
////    // Implementation of reading the student records from a file
////    // ...
////}
////
////void students::saveList(const struct student* node, FILE* list) {
////    // Implementation of saving the student records to a list
////    // ...
////}
////
////struct student* students::DeleteStudentRecord(struct student* root, char* name) {
////    struct student* remove = search(root, name);
////    struct student* var1 = NULL;
////    struct student* var2 = NULL;
////    struct student* var3 = NULL;
////
////    if (remove->parent) {
////        struct student* Parent = remove->parent;
////        if (Parent->parent) {
////            var1 = Parent->parent->left;
////            var2 = Parent->parent->right;
////        }
////
////        if (var1 == Parent) {
////            var3 = var1;
////        }
////        else if (var2 == Parent) {
////            var3 = var2;
////        }
////        else {
////            cout << "Error in DeleteStudentRecord: Parent not recognized." << endl;
////        }
////
////        if (var3) {
////            if (var3->left == Parent) {
////                var3->left = NULL;
////            }
////            else if (var3->right == Parent) {
////                var3->right = NULL;
////            }
////            else {
////                cout << "Error in DeleteStudentRecord: var3 not recognized." << endl;
////            }
////        }
////        delete remove;
////        return root;
////    }
////    else {
////        delete remove;
////        return NULL;
////    }
////}

