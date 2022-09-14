#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

//reads data from .txt file
void ReadFile(int &n, vector<int> &input_vector)
{
	string line, size;
	ifstream in("D:\input.txt");
	getline(in, size);
	getline(in, line);
	in.close();

	n = stoi(size);
	
	istringstream input{ line };
	while (!input.eof())
	{
		string temp;
		input >> temp;
		input_vector.push_back(stoi(temp));
	}
}

//writes results in .txt file
void WriteFile(vector<vector<int>> answer_subsets, int answer_num)
{
	int print_num;
	ofstream out("D:\output.txt", ios::app);

	if (answer_num > 0)
	{
		out << "YES" << endl;

		if (answer_num < 4)
			print_num = answer_num;
		else print_num = 3;

		for (int i = 0; i < print_num; i++)
		{
			for (int j = 0; j < answer_subsets[i].size(); j++)
			{
				out << answer_subsets[i][j] << " ";
			}
			out << endl;
		}
	}
	else
		out << "NO";

	out << endl << answer_num;
	out.close();
}

//puts all subsets that meet requerments in output variable and amount of those subsets in answers_num variable
void Decode(vector<vector<int>> input, int N, vector<vector<int>> &output, int &answers_num)
{
	for (int i = 0; i < input.size(); i++)
	{
		int temp_sum = 0;
		for (int j = 0; j < input[i].size(); j++)
		{
			temp_sum += input[i][j];
		}
		if (temp_sum % N == 0)
			output.push_back(input[i]);
	}

	answers_num = output.size();
}

//returns all subsets(except empty) from given set as vector of vectors
vector<vector<int>> GetSubsets(vector<int> num_input, int size)
{
	int subset_num = (1 << size);
	vector<vector<int>> all_subsets;

	for (int subset_mask = 0; subset_mask < subset_num; subset_mask++)
	{
		vector<int> subset;
		for (int i = 0; i < size; i++)
		{
			if ((subset_mask & (1 << i)) != 0)
				subset.push_back(num_input[i]);
		}
		if(not subset.empty())
			all_subsets.push_back(subset);
	}

	return all_subsets;
}

//prints elements from vector of vectors in console
void PrintVector(vector<vector<int>> vec_input)
{
	for (int i = 0; i < vec_input.size(); i++)
	{
		for (int j = 0; j < vec_input[i].size(); j++)
		{
			cout << vec_input[i][j] << " ";
		}
		cout << "\n";
	}
}

int main()
{
	int N;
	vector<int> input;
	vector<vector<int>> result;
	int result_count;

	ReadFile(N, input);
	Decode(GetSubsets(input, N), N, result, result_count);
	WriteFile(result, result_count);
	PrintVector(result);
}