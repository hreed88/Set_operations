#include <vector>
#include <iostream>
using namespace std;

/*
Author: Harrison Reed
Date: 9/28/2023
Resources used: Geeksforgeeks.org
Collaborator(s): None
Name:
Descripton: C++ code to calulate certain set operations, and properties of Relations
Outputs: Prints out each problem 



*/


/*
Author: Harrison Reed
contains is to check if a set pair is contained in vector
Variables: thisArr, this pair
Return: True if pair is contained in vector, false if not
*/
bool contains(vector<vector<int>> thisArr, vector<int> thisPair) {
	
	for (int i = 0; i < thisArr.size(); i++) {
		if (thisArr[i][0] == thisPair[0] && thisArr[i][1] == thisPair[1]) {//Loop through each item in the vector, and check if both items at posistion i match thisPair
			return true;//if so return true as we found a  match
		}
	}

	return false;//False if not 

}


/*
Author: Harrison Reed
containsBC is to check and see if there exists an element that contains an element in posistion 0 of (b,c) in the vector
Variables: thisArr, B, C
Return: True if there exists (b,c) in the vector, false if not
*/
bool containsBC(vector<vector<int>> thisArr,int B,int* C ) {

	for (int i = 0; i < thisArr.size(); i++) {
		if (thisArr[i][0] == B) {//loop through vector to see if there exsists element at [i][0] That is equivalent to B
			*C = thisArr[i][1];//if so point c to the value at the second posistion of this item and return true
			return true;
		}
	}

	return false;//false if not

}

/*
Author: Harrison Reed
printVector is to print vector(mainly for problem 2 and 3), in the format {{0,0,0},
																		   {0,0,0}}
Variables: thisVect
Return: none
*/
void printVector(vector<vector<int>> thisVect) {

	for (int i = 0; i < thisVect.size(); i++) {//loop through each row of vector
		
		cout << "{";
		for (int j = 0; j < thisVect[i].size(); j++) {//loop through each column of vector
		cout << thisVect[i][j];//print item at [row][column]
		if ((j + 1) != thisVect[i].size())
			cout << ",";
		}
		cout << "}";
		if ((i + 1) != thisVect.size())
			cout << " , ";
		cout << "\n";
	}
	cout << "\n }";

}

/*
Author: Harrison Reed
printOrderedPair is to print vector(mainly for problem 1 and 4), in the format {{0,0},{0,0},...}
Variables: thisVect
Return: none
*/
void printOrderedPair(vector<vector<int>> thisVect) {

	cout << "{ ";
	for (int i = 0; i < thisVect.size(); i++) {//loop through each row of vector

		cout << "{";
		for (int j = 0; j < thisVect[i].size(); j++) {//loop through each column of vector
			cout << thisVect[i][j];//print item at [row][column]
			if ((j + 1) != thisVect[i].size())
				cout << ",";
		}
		cout << "}";
		if ((i + 1) != thisVect.size())
			cout << " , ";
	}
	cout << " }\n";

}


/*
Author: Harrison Reed
composite is used to calculate the boolean multiplication of two relations (1 and 0 ) or (0 and 0) or ...
Variables: rel1(relation 1), rel2(relation 2)
Return: returns the composite of the two vectors passed to composite
*/
vector<vector<int>> composite(vector<vector<int>> rel1, vector<vector<int>> rel2) {

	vector<vector<int>> compositeMatrix(rel1.size(), vector<int>(rel2[0].size()));//create a composite vector that is the size of rel1 X rel2 (ex. (3 X 4) * (4 X 3) will create new matrix of size 3 X 3

	for (int i = 0; i < rel1.size(); i++) {//loop through the size of rows of rel1
			for (int j = 0; j < rel2[0].size(); j++) {//loop through the size of columns of rel2
				int tempInt = 0;//keep track of the sum of the values of rel1[i][k] * rel[k][j](initilize to zero after looping through the size of columns on rel1
				for (int k = 0; k < rel1[0].size(); k++) {//loop through the size of coluimns of rel1
					tempInt += rel1[i][k] * rel2[k][j]; //compute the composite for new matrix ie (rel1[0][0] * rel2[0][0]) or ... (rel[0][rel1[0].size] * rel2[rel1[0].size()][0])
				}										//this follows the form composite = sum(rel1[i][k] * rel2[k][j]
				if(tempInt >= 1)
					compositeMatrix[i][j] = 1;// Since we only care about the boolean composite, if our tempInt is >= 1 then we know that for that item in the composite matrix the result will be 1, and zero if not
			}
			
			

	}

	return compositeMatrix;
}

/*
Author: Harrison Reed
problem1 is driver function used to do subproblems in problem 1
Resources used: Geeksforgeeks.org
Variables:None
Return: None
*/
void problem1() {
	vector<vector<int>> relation1 = { {1,1},{2,2},{3,3} }; //create 1st relation
	vector<vector<int>> relation2 = { {1,1},{1,2},{1,3},{1,4} }; //create 2nd relation

	//-----------------------------------------------------------------------------
	//Problem 1 a, union of relation1 and relation 2
	cout << "\nProblem 1A\n-----------------------------------------------------------------------------";
	vector<vector<int>> myUnion; //new vector to add items from both relations

	for (int i = 0; i < 4; i++) {//since it is a union make myUnion a "copy" of relation 2
		myUnion.push_back(relation2[i]);
	}

	for (int i = 0; i < relation1.size(); i++) {//Now we only need to check the values in relation 1
		if (!contains(myUnion, relation1[i]))//if the item at i in relation 1 is already in myUnion we dont need to add it
			myUnion.push_back(relation1[i]);//if it is not add it to my union
	}
	//Print out union
	cout << "\nThe union between the two relations { {1,1},{2,2},{3,3} } and { {1,1},{1,2},{1,3},{1,4} } is \n \n";
	printOrderedPair(myUnion); //use ordered pair for this
	
	//-----------------------------------------------------------------------------
	//Problem 1 b, intersection of relation 1 and relation 2
	cout << "\nProblem 1B\n-----------------------------------------------------------------------------";
	vector<vector<int>> myIntersection; //new vector to add items that are only in both rel 1 and rel 2

	for (int i = 0; i < relation2.size(); i++) {
		if (contains(relation1, relation2[i])) {//loop through to see if item at i in relation 2 is in relation 1
			myIntersection.push_back(relation2[i]);//if so we just need to add from 1 relation because they are in both relations(no duplicates)
		}
	}

	//print out intersection
	cout << "\nThe intersection between the two relations { {1,1},{2,2},{3,3} } and { {1,1},{1,2},{1,3},{1,4} } is \n \n";
	printOrderedPair(myIntersection);

	//-----------------------------------------------------------------------------
	//problem 1 c, the difference of relation1 - relation2
	cout << "\nProblem 1C\n-----------------------------------------------------------------------------";
	vector<vector<int>> difference12; //new vector to add items that is the difference between rel 1 rel 2

	for (int i = 0; i < relation1.size(); i++) {//loop through relation 1 since we are subtracting from it(only care about whats in rel 1)
		if (!contains(relation2, relation1[i])) {//if relation 2 does not contain item at i in relation 1, we cannot subtract it from relation 1, so add it to difference12
			difference12.push_back(relation1[i]);
		}
	}

	//print out differnece of relation1 - relation2
	cout << "\nThe diffrence of  { {1,1},{2,2},{3,3} } - { {1,1},{1,2},{1,3},{1,4} } is \n\n";
	printOrderedPair(difference12);
	//-----------------------------------------------------------------------------
	//problem 1 d, the difference of relation2 - relation1
	cout << "\nProblem 1D\n-----------------------------------------------------------------------------";
	vector<vector<int>> difference21;//new vector to add items that is the difference between rel 2 rel 1

	for (int i = 0; i < relation2.size(); i++) {//loop through relation 2 since we are subtracting from it(only care about whats in rel 2)
		if (!contains(relation1, relation2[i])) {//if relation 1 does not contain item at i in relation 2, we cannot subtract it from relation 2, so add it to difference21
			difference21.push_back(relation2[i]);
		}
	}

	//print out differnece of relation2 - relation1
	cout << "\nThe diffrence of  { {1,1},{1,2},{1,3},{1,4} } - { {1,1},{2,2},{3,3} } is \n \n";
	printOrderedPair(difference21);
}

/*
Author: Harrison Reed
problem2 is driver function used to do problem2
Resources used: none
Variables:None
Return: None
*/
void problem2() {

	//-----------------------------------------------------------------------------
	//Problem 2, union of relation1 and relation 2
	cout << "\nProblem 2\n-----------------------------------------------------------------------------";

	vector<vector<int>> relation1 = {  {1, 0, 1},//create relation 1
									   {0, 0, 0},
									   {0, 1, 0},
									   {1, 0, 1} };

	vector<vector<int>> relation2 = {  {1, 1, 0, 0},//create relation 2
									   {0, 0, 1, 1},
									   {0, 1, 1, 0} };




	vector<vector<int>> compositeVec = composite(relation1, relation2);//use our composite function to calculate the composite of the two
	
	cout << "\n\nThis is the composite of the relation {(1, 1), (1, 4), (2, 3), (3, 1), (3, 4)}\n and {(1, 0), (2, 0), (3, 1), (3, 2), (4, 1)}\n{\n\n";
	printVector(compositeVec);

	
									 
}

/*
Author: Harrison Reed
problem3 is driver function used to do problem3
Resources used: none
Variables:None
Return: None
*/
void problem3() {

	//-----------------------------------------------------------------------------
	//Problem 3, the relation squared
	cout << "\nProblem 3\n-----------------------------------------------------------------------------";

	vector<vector<int>> relation = {   {1, 0, 1},//create relation 1
									   {0, 0, 0},
									   {0, 1, 0},
									   {1, 0, 1} };
	vector<vector<int>> relationSquared = { {1, 0, 1, 0},//create relation 2, which is just relation however since we cannot mutiply a 3x4 * 3x4 we must "square it"
									        {0, 0, 0, 0},
									        {0, 1, 0, 0},
									        {1, 0, 1, 0} };





	vector<vector<int>> compositeVec = composite(relationSquared, relation);//use composite function to calculate r^2 becuase r^2 is just the composite of a relation by itself

	cout << "\n\nThis is the R^2 of the relation {(1, 1), (1, 4), (2, 3), (3, 1), (3, 4)}\n{\n\n";
	printVector(compositeVec);



}

/*
Author: Harrison Reed
isReflexife is used to see if a relation is reflexive
Resources used: none
Variables:thisRelation, thisSet
Return: bool
*/
bool isReflexive(vector<vector<int>> thisRelation, vector<int> thisSet) {
	
	bool reflexive = true;//Assume that the relation is reflexive unless we find otherwise

	for (int i = 0; i < thisSet.size(); i++) {
		cout << "\ncheck if (" << thisSet[i] << "," << thisSet[i] << ") is contained in the relation: ";
		if (!contains(thisRelation, { thisSet[i],thisSet[i] })) {//check to see if item at thisSet[i] is in both posistions(a,a)
			cout << "(" << thisSet[i] << ", " << thisSet[i] << ") is not in the relation";//must be true for all items in the set, so if we find one thats not in the relation we set our answer to false
			reflexive = false;//set to false
		}
		else
			cout << "(" << thisSet[i] << ", " << thisSet[i] << ") is in the relation";
		}

	return reflexive;
}

/*
Author: Harrison Reed
isSymetric is used to see if a relation is symmetric
Resources used: none
Variables:thisRelation
Return: bool
*/
bool isSymmetric(vector<vector<int>> thisRelation) {

	bool symmetric = true;//Assume that the relation is symmetric unless we find otherwise

	for (int i = 0; i < thisRelation.size(); i++) {
		cout << "\nCurrent item in the relation (" << thisRelation[i][0] << "," << thisRelation[i][1] << ")";//display what item were on in the relation(a, b)
		cout << "\nCheck if (" << thisRelation[i][1] << "," << thisRelation[i][0] << ") is contained in the relation: ";//check to see if (b,a) is in the relation
		if (!contains(thisRelation, { thisRelation[i][1],thisRelation[i][0] })) {//if it is not contained in the relation set symmetric to false, this is becuase all a,b must have b,a
			cout << "(" << thisRelation[i][1] << ", " << thisRelation[i][0] << ") is not in the relation";
			symmetric = false;
		}
		else
			cout << "(" << thisRelation[i][1] << ", " << thisRelation[i][0] << ") is in the relation";
	}

	return symmetric;
}

/*
Author: Harrison Reed
isAntiSymetric is used to see if a relation is anyisymmetric
Resources used: none
Variables:thisRelation
Return: bool
*/
bool isAntiSymmetric(vector<vector<int>> thisRelation) {

	bool antiSymmetric = true;//Assume that the relation is antiSymmetric unless we find otherwise

	for (int i = 0; i < thisRelation.size(); i++) {
		cout << "\nCurrent item in the relation (" << thisRelation[i][0] << "," << thisRelation[i][1] << ")";//display what item were on in the relation(a, b)
		cout << "\nCheck if (" << thisRelation[i][1] << "," << thisRelation[i][0] << ") is not contained in the relation: ";//check to see if (b,a) is not in the relation
		if (!contains(thisRelation, { thisRelation[i][1],thisRelation[i][0] })) {
			cout << "(" << thisRelation[i][1] << ", " << thisRelation[i][0] << ") is not in the relation";
			
		}
		else {//if it is contained in the relation set antisymmetric to false, this is becuase all a,b must not have b,a
			cout << "(" << thisRelation[i][1] << "," << thisRelation[i][0] << ") is in the relation";
			antiSymmetric = false;
		}
		}

	return antiSymmetric;
}


/*
Author: Harrison Reed
isTransitive is used to see if a relation is Transitive
Resources used: none
Variables:thisRelation
Return: bool
*/
bool isTransitive(vector<vector<int>> thisRelation) {
	bool transitive = true;//Assume that the relation is transitive unless we find otherwise

	for (int i = 0; i < thisRelation.size(); i++) {
		cout << "\nCurrent item in the relation (" << thisRelation[i][0] << "," << thisRelation[i][1] << ")"; //display what item were on
		cout << "\nCheck if (" << thisRelation[i][1] << ", C) exists"; //check to see if there exits (b,c)
		int myC;
		if (containsBC(thisRelation, thisRelation[i][1], &myC)) {
			cout << "\nThere exists a C such that ("<< thisRelation[i][1] << "," << myC<< ") exists";//if (b,c) does exist check to see if (a,c) also exists
			if (!contains(thisRelation, { thisRelation[i][0], myC })) {//if not the set is not transitve and set transitive to false
				cout << "\n(" << thisRelation[i][0] << ", " << myC << ") is not in the relation";
				transitive = false;
			}
			else {
				cout << "\n(" << thisRelation[i][1] << ", " << myC << ") is in the relation";
			}
		}
		
	}

	return transitive;
}

/*
Author: Harrison Reed
problem4 is used to do problem 4
Resources used: none
Variables:none
Return: none
*/

void problem4() {
//-----------------------------------------------------------------------------
//Problem 4
	cout << "\nProblem 4\n-----------------------------------------------------------------------------";
	vector<vector<int>> myRelation;
	vector<int> mySet;

	for (int i = -10; i <= 10; i++)//create the set of [-10,..10]
		mySet.push_back(i);

	for (int i = -10; i <= 10; i++) {//create the relation f(x,y)| x+y =0
		for (int j = -10; j <= 10; j++) {
			if (i + j == 0)
				myRelation.push_back({ i,j });
		}
	}
	cout << "\nProblem 4 Part A:\nThe ordered pairs of R = {(x,y) | x + y = 0}, on the set {-10,-9,...,9,10} is\n\n";
	printOrderedPair(myRelation);
	cout << "\n-----------------------------------------------------------------------------";

	cout << "\nProblem 4 Part b:\nFor our relation to be reflexive we must show that it contains (a,a) for every a e A\n";
	cout << "So we must show that R contains {(-10,-10), (-9,-9), ... ,(9, 9), (10,10)}";
	cout << "\nIf we loop through the entire array and check to see if for all of the items in the set our at both posistions at any given index\n\n";

	if (isReflexive(myRelation, mySet)) {
		cout << "\nThe relation is reflexive\n";
	}
	else
		cout << "\nThe relation is not reflexive\n";

	cout << "\n-----------------------------------------------------------------------------";
	cout << "\nProblem 4 Part C:\nFor our relation to be symmetric we must show that if it contains (a,b), then it must also contain (b,a) for every a e B and b e A\n";

	if (isSymmetric(myRelation)) {
		cout << "\nThe relation is Symmetric\n";
	}
	else
		cout << "\nThe relation is not Symmetric\n";

	cout << "\n-----------------------------------------------------------------------------";
	cout << "\nProblem 4 Part D:\nFor our relation to be antisymmetric we must show that if it contains (a,b), then it must not contain (b,a) for every a e B and b e A\n";
	if (isAntiSymmetric(myRelation)) {
		cout << "\nThe relation is AntiSymmetric\n";
	}
	else
		cout << "\nThe relation is not AntiSymmetric\n";

	cout << "\n-----------------------------------------------------------------------------";
	cout << "\nProblem 4 Part E:\nFor our relation to be transitive we must show that if it contains (a,b) and (b,c), then it must also contain (a,c) for every a e A and b e A, c e A\n";
	if (isTransitive(myRelation)) {
		cout << "\nThe relation is Transitive\n";
	}
	else
		cout << "\nThe relation is not Transitive\n";

}

/*
Author: Harrison Reed
main is driver function for assignment 3
Resources used: none
Variables:none
Return: 0
*/
int main() {

	int userInp = 0;
	bool isRunning = true;

	while (isRunning) {
		cout << "\nPlease enter an option\n1) Problem 1\n2) Problem 2\n3) Problem 3\n4) Problem 4\n5) Exit\n";
		cin >> userInp;
		switch (userInp) {
		case 1:
			problem1();
			break;
		case 2:
			problem2();
			break;
		case 3:
			problem3();
			break;
		case 4:
			problem4();
			break;
		case 5:
			isRunning = false;
			break;
		default:
			break;
		}
	}
	return 0;
}
