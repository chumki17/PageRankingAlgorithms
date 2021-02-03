#include <iostream>
#include <vector>
using namespace std;

vector<vector<double> > createTransitionMatrix(int n)
{
	vector<vector<double> > matrix;
	vector<double> row(n,0);
	for(int i=0; i<n; i++)
		matrix.push_back(row);
	return matrix;
}

vector<vector<double> > createVector(int n)
{
    vector<vector<double> > vect;
	double temp=(double)1/n;
    vector<double> row(1,temp);
	for(int i=0; i<n; i++)
	    vect.push_back(row);
	return vect;
}

vector<vector<double> > initRank(int n)
{
    vector<vector<double> > rank;
	vector<double> row(1,0.0);
	for(int i=0; i<n; i++)
	    rank.push_back(row);
	return rank;
}


vector<vector<double> > initTransitionMatrix(vector<vector<double> > matrix)
{
    int n , node;
	vector<int> row;
	for(int i=0; i< matrix.size(); i++)
    {
	   cout << "Enter the no. of outgoing edges for node "<<i<<" : ";
	   cin >> n;
	   if(n > 0)
	   {
	      cout << "Enter the nodes: ";
		  for(int j=0; j<n; j++)
		  {
		      cin >> node;
			  row.push_back(node);
          }
		  for(int j=0; j < row.size(); j++)
		     matrix[row[j]][i]=(double)1/n;
		  row.clear();
	   }
	}
	return matrix;
}

int equalsMatrix(vector<vector<double> > mat , vector<vector<double> > matrix)
{
    if(mat.size()!=matrix.size())
		return -1;
	for(int i=0; i<mat.size(); i++)
	{
	    if(mat[i].size()!=matrix[i].size())
		    return -1;
		for(int j=0; j<mat[i].size(); j++)
		   if(mat[i][j] != matrix[i][j])
		       return -1;
	}
	return 0;
}

vector<vector<double> > multiply(vector<vector<double> > matrix , vector<vector<double> > mat)
{
	vector<vector<double> > result;
	result=initRank(mat.size());
	for(int i=0; i<matrix.size(); i++)
    {
		for(int j=0; j<mat[i].size(); j++)
		{
		    result[i][j]=0;
		    for(int k=0; k<matrix[i].size(); k++)
		    result[i][j]=result[i][j]+(matrix[i][k] * mat[k][j]);
		}
	}
	return result;
}

vector<vector<double> > createRankMatrix(vector<vector<double> > transitionMatrix , vector<vector<double> > vect)
{
	int count=0;
	vector<vector<double> > rank;
	vector<vector<double> > res;
	rank=initRank(vect.size());
	res=multiply(transitionMatrix , vect);
	rank=multiply(transitionMatrix , res);

	while(equalsMatrix(rank , res)!=0)
	{
	   	res=multiply(transitionMatrix , rank);
		rank=multiply(transitionMatrix , res);
	}
	return rank;
}

int main()
{
    int n=0;
	vector<vector<double> > transitionMatrix;
	vector<vector<double> > vect;
	vector<vector<double> > rank;
	cout<< "Enter no. of nodes : ";
	cin >> n;
	/*------- CREATE VECTOR AND TRANSITION MATRIX FOR THE GIVEN GRAPPH-------*/
	vect = createVector(n);
	rank = initRank(n);
    transitionMatrix = createTransitionMatrix(n);
	/*----INITIALISE TRANSITION MATRIX BASED ON THE OUT-DEGREE OF THE NODES---*/
	transitionMatrix=initTransitionMatrix(transitionMatrix);
	/*----INITIALISE TRANSITION MATRIX BASED ON THE OUT-DEGREE OF THE NODES---*/
	rank=createRankMatrix(transitionMatrix , vect);
    /*---------------------PRINT THE PAGE RANK MATRIX-------------------------*/
	cout<< "The Page Rank Matrix is : " << endl;
	for(int i=0; i < rank.size(); i++)
	{
	    for(int j=0; j<rank[i].size(); j++)
	        cout << rank[i][j] << "  ";
	    cout << endl;
	}
	return 0;
}
