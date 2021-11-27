#pragma once
#include "MyForm.h"
#include <fstream>
#include <Windows.h>
#include <msclr\marshal_cppstd.h>
#define backtostring msclr::interop::marshal_as<std::string>
#define gotoString msclr::interop::marshal_as<String^>
using namespace std;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

int DSGrammarly::MyForm::tenseteller(Node* verbform)
{
	if (verbform == NULL)
		return -1;
	else if (verbform->prev == NULL && verbform->next == NULL)
		return 4;
	else if (verbform->next == NULL && verbform->prev != NULL)
		return 4;
	else if (verbform->prev == NULL && verbform->next != NULL)
		return 1;
	else if (verbform->next->next == NULL && verbform->prev->prev->prev == NULL)
		return 3;
	else if (verbform->next->next->next == NULL && verbform->prev->prev == NULL)
	{
		if (verbform->content == verbform->next->content)
			return 5;
		else
			return 2;
	}
	else if (verbform->prev == NULL && verbform->next != NULL)
		return 1;

}
vector<string> DSGrammarly::MyForm::algorithm(string sentence)
{
	Node* helping = NULL, * verb = NULL;
	char word[15];
	int i, j;
	int pronouns = 2; //0 = signular 1= plural
	bool status = 1; //to allow search for verb and helping verb
	string pronoun;
	vector<string> new_sentence;
	
//This is a very crucial for loop. please edit with caution. searches for verb. helping verb. preposition. pronoun. 
	//also constructs invidual words from a string
	for (i = 0, j = 0; j < sentence.size() + 1; i++, j++)
	{

		if (sentence[j] == ' ' || sentence[j] == ',' || sentence[j] == '?' || sentence[j] == '.' || sentence[j] == '\n' || sentence[j] == '\0')
		{
			word[i] = '\0';
			if (word[i - 1] == 't' && word[i - 2] == 'n')
			{
				string temp;
				temp = "not";
				word[i - 2] = '\0';
				i = i - 2;
				if (_strcmpi(word, "ca") == 0)
				{
					word[i] = 'n';
					word[i + 1] = '\0';
				}
				else if (_strcmpi(word, "wo") == 0)
				{
					word[i - 2] = 'i';
					word[i - 1] = 'l';
					word[i] = 'l';
					word[i + 1] = '\0';
				}
				else if (_strcmpi(word, "ai") == 0)
				{
					if (pronouns == 0)
					{
						word[i - 2] = 'i';
						word[i - 1] = 's';
						word[i] = '\0';
					}
					else if (pronouns == 1)
					{
						word[i - 2] = 'a';
						word[i - 1] = 'r';
						word[i ] = 'e';
						word[i+1] = '\0';
					}
				}
				new_sentence.push_back(word);
				new_sentence.push_back(temp);
				i = -1;
				goto test;
			}
			new_sentence.push_back(word);
			i = -1;
		test:
			if (status == 1&&pronouns==2 && (_strcmpi(word, "i") == 0 || _strcmpi(word, "he") == 0 || _strcmpi(word, "she") == 0 || _strcmpi(word, "it") == 0))
			{
				pronouns = 0;
				pronoun = word;
			}
			else if (status == 1 && pronouns == 2 && (_strcmpi(word, "they") == 0 || _strcmpi(word, "we") == 0 || _strcmpi(word, "you") == 0))
			{
				pronouns = 1;
				pronoun = word;
			}
			else if (prepositions->search(word) != NULL && helping != NULL)
				status = 0;
			else if (status == 1 && helping_verbs->search(word) != NULL)
				helping = helping_verbs->search(word);
			else if (status == 1 && verbs->search(word) != NULL)
				verb = verbs->search(word);
			continue;
		}
		word[i] = sentence[j];
		if (word[i] > 64 && word[i] < 91 && j != 0)
		{
			word[i] = word[i] + 32;
		}
		if (sentence[j] == '\'')
		{
		notcorrector:
			word[i] = '\0';

			string temp;
			if (sentence[j + 1] == 's')
			{
				temp = "is";
				helping = helping_verbs->search("is");
				j += 2;
			}
			else if (sentence[j + 1] == 'v' && sentence[j + 2] == 'e')
			{
				temp = "have";
				helping = helping_verbs->search("have");
				j += 3;
			}
			else if (sentence[j - 1] == 'n' && sentence[j + 1] == 't')
			{
				temp = "not";
				j += 2;
				if (_strcmpi(word, "ca") == 0)
				{
					word[i] = 'n';
					word[i + 1] = '\0';
				}
				else if (_strcmpi(word, "won") == 0)
				{
					word[i - 2] = 'i';
					word[i - 1] = 'l';
					word[i] = 'l';
					word[i + 1] = '\0';
				}
				else if (_strcmpi(word, "ain") == 0)
				{
					if (pronouns == 0)
					{
						word[i - 3] = 'i';
						word[i - 2] = 's';
						word[i - 1] = '\0';
					}
					else if (pronouns == 1)
					{
						word[i - 3] = 'a';
						word[i - 2] = 'r';
						word[i - 1] = 'e';
						word[i] = '\0';
					}
				}
				else if (!(_strcmpi(word, "can") == 0))
				{
					word[i - 1] = '\0';
				}
			}
			new_sentence.push_back(word);
			new_sentence.push_back(temp);
			i = -1;
			goto test;
		}
	}
	//word[i] = '\0';
	//new_sentence.push_back(word);
	//simple present ignored. no edits possible/needed since we work solely on the helping verb
	//simple past
	if ((helping != NULL && tenseteller(helping) == 4) && (helping->content != "have" && helping->content != "has" && helping->content != "been" && helping->content != "had") && (tenseteller(verb) == 2 || tenseteller(verb) == 5))
	{
		if (helping != NULL)
		{
			auto pos = find(new_sentence.begin(), new_sentence.end(), helping->content);
			int index = pos - new_sentence.begin();
			if (tenseteller(helping) == 4)
			{
				auto pos2 = find(new_sentence.begin(), new_sentence.end(), verb->content);
				int index2 = pos2 - new_sentence.begin();
				new_sentence[index2] = verb->prev->content;
			}
		}
	}
	//perfect contninuous tense
	else if (helping != NULL && helping->content == "been" && tenseteller(verb) == 4)
	{
		auto pos = find(new_sentence.begin(), new_sentence.end(), helping->content);
		int index = pos - new_sentence.begin();

		if (helping_verbs->search(new_sentence[index - 1]) != NULL || helping_verbs->search(new_sentence[index - 2]) != NULL)
		{
			if (index - 3 > -1)
				if (new_sentence[index - 3] == "will")
					new_sentence[index - 1] = "have";
			if (new_sentence[index - 2] == "will")
				new_sentence[index - 1] = "have";

			else if (tenseteller(helping_verbs->search(new_sentence[index - 1])) == 1)
			{
				new_sentence[index - 1] = pronouns == 0 ? ("has") : (new_sentence[index - 1] = pronouns == 1 ? ("have") : (new_sentence[index - 1]));
				new_sentence[index - 1] = pronoun == "i" ? ("have") : (new_sentence[index - 1]);

			}
			else if (tenseteller(helping_verbs->search(new_sentence[index - 1])) == 4)
				new_sentence[index - 1] = "had";
			else if (tenseteller(helping_verbs->search(new_sentence[index - 2])) == 1)
			{
				new_sentence[index - 2] = pronouns == 0 ? ("has") : (new_sentence[index - 2] = pronouns == 1 ? ("have") : (new_sentence[index - 1]));
				new_sentence[index - 2] = pronoun == "i" ? ("have") : (new_sentence[index - 2]);
			}
			else if (tenseteller(helping_verbs->search(new_sentence[index - 2])) == 4)
				new_sentence[index - 2] = "had";
		}
		else
		{
			new_sentence.insert(pos, pronouns == 0 ? ("has") : ("have"));
		}



	}
	//Continous tense below
	else if ((tenseteller(helping) == 4 || tenseteller(helping) == 1) && tenseteller(verb) == 4)
	{

		auto pos = find(new_sentence.begin(), new_sentence.end(), helping->content);
		int index = pos - new_sentence.begin();
		//future tense exception
		if (index - 2 > -1)
			if (new_sentence[index - 2] == "will")
			{
				//helping = helping_verbs->search("will be");
				new_sentence[index] = "be";
			}
		if (index != 0 && (new_sentence[index - 1] == "will"))
		{
			//helping = helping_verbs->search("will be");
			new_sentence[index] = "be";
		}
		//others
		else
		{

			if (tenseteller(helping) == 1)
			{
				if (pronoun == "i")
					new_sentence[index] = "am";
				else
					new_sentence[index] = pronouns == 0 ? ("is") : (new_sentence[index] = pronouns == 1 ? ("are") : (new_sentence[index]));
			}
			if (tenseteller(helping) == 4)
				new_sentence[index] = pronouns == 0 ? ("was") : (new_sentence[index] = pronouns == 1 ? ("were") : (new_sentence[index]));
		}
	}
	//perfect tense below
	else if ((tenseteller(helping) == 4 || tenseteller(helping) == 1) && (tenseteller(verb) == 3 || tenseteller(verb) == 5))
	{
		auto pos = find(new_sentence.begin(), new_sentence.end(), helping->content);
		int index = pos - new_sentence.begin();
		//future tense exception
		if (index != 0 && new_sentence[index - 1] == "will")
		{
			//helping = helping_verbs->search("will be");
			new_sentence[index] = "have";
		}
		else if (helping->content == "been")
		{
			new_sentence.erase(pos);
		}
		//others
		else
		{

			if (tenseteller(helping) == 1)
			{
				new_sentence[index] = pronouns == 0 ? ("has") : (new_sentence[index] = pronouns == 1 ? ("have") : (new_sentence[index]));
				new_sentence[index] = pronouns == 0 ? ("has") : ("have");
				new_sentence[index] = pronoun == "i" ? ("have") : (new_sentence[index]);
			}
			if (tenseteller(helping) == 4)
				new_sentence[index] = "had";
		}
	}
//returning first letter as capital
	if(new_sentence[0][0]>97&& new_sentence[0][0]<123)
		new_sentence[0][0] = new_sentence[0][0] - 32;
	return new_sentence;
}
void DSGrammarly::MyForm::contentloader()
{
	ifstream helpingverbs_file("helping_verbs.txt");
	ifstream verbs_file("verbs.txt");
	ifstream preposition_file("prepositions.txt");
	bool status = true;
	char reader;
	char word[15];
	int i;
	Node* currhashed = NULL;
	if (!helpingverbs_file.is_open())
	{
		cout << "Helping Verb file did not open!\n";
	}
	else
	{

		for (i = 0; helpingverbs_file >> noskipws >> reader; i++)
		{

			if (status == true && reader == ',')
			{
				word[i] = '\0';
				i = -1;
				currhashed = helping_verbs->enter(word);
				status = false;
				continue;
			}
			else if (status == false && (reader == ',' || reader == '\n'))
			{
				word[i] = '\0';
				i = -1;
				currhashed = helping_verbs->linkpastpresent(currhashed, word);
				status = reader == '\n' ? (true) : (false);
				continue;
			}
			if (reader == '\n')
			{
				word[i] = '\0';
				i = -1;
				currhashed = helping_verbs->enter(word);
				status = reader == '\n' ? (true) : (false);
				continue;
			}
			word[i] = reader;

		}
		helpingverbs_file.close();

		currhashed = NULL;
	}
	if (!verbs_file.is_open())
	{
		cout << "Verbs File did not open!\n";
	}
	else
	{
		status = true;
		for (i = 0; verbs_file >> noskipws >> reader; i++)
		{
			if (reader > 64 && reader < 91)
				reader = reader + 32;
			if (status == true && reader == ',')
			{
				word[i] = '\0';
				i = -1;
				currhashed = verbs->enter(word);
				status = false;
				continue;
			}
			else if (status == false && (reader == ',' || reader == '\n'))
			{
				word[i] = '\0';
				i = -1;
				currhashed = verbs->linkpastpresent(currhashed, word);
				status = reader == '\n' ? (true) : (false);
				continue;
			}
			word[i] = reader;
		}
	}
	if (!preposition_file.is_open())
	{
		cout << "Prepositions File did not open!\n";
	}
	else
	{
		for (i = 0; preposition_file >> noskipws >> reader; i++)
		{
			if (reader > 64 && reader < 91)
				reader = reader + 32;
			if (reader == '\n')
			{
				word[i] = '\0';
				i = -1;
				currhashed = prepositions->enter(word);
				continue;
			}
			word[i] = reader;
		}
	}


	//verbs.print();
}
void DSGrammarly::MyForm::consolestatus(int which)
{
	if(which ==1)
		ShowWindow(GetConsoleWindow(), SW_HIDE);
	else if(which ==2)
		ShowWindow(GetConsoleWindow(), SW_RESTORE);
}
void DSGrammarly::MyForm::InputButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	OutputBox->Text = "";
	string input = backtostring(InputBox->Text);
	int sentencecount = 0;
	int i = 0; int j = 0, k=0;
	for (i = 0; i < input.size(); i++)
	{
		if (input[i] == '.'|| input[i] == '?'|| input[i] == '!')
			sentencecount++;
	}
	string* sentences = new string[sentencecount + 1];
	char word[15];
	for (i = 0, j = 0, k=0; j < sentencecount + 1; i++,k++)
	{
		if (k == input.size())
			goto endit;
		if (input[k] == ' ' || input[k] == ',' || input[k] == '\n' || input[k] == '\0')
		{
			word[i] = '\0';
			if (_strcmpi(word, "") == 0)
				goto cont;
			sentences[j] = sentences[j] +  word + " ";
			cont:
			i = -1;
			continue;
		}
		if (input[k] == '.'|| input[k] == '!'|| input[k] == '?')
		{
			endit:
			word[i] = '\0';
			sentences[j] += word;
			i = -1;
			j++;
			continue;
		}
		word[i] = input[k];
	}
	OutputBox->AppendText("Suggestions: " + Environment::NewLine);
	for (int j = 0; j < sentencecount+1; j++)
	{
		vector<string> output;
		if (sentences[j] != "")
		{
			output = algorithm(sentences[j]);
			string str;
			for (int i = 0; i < output.size(); i++)
			{
				str = str + output[i] + " ";
			}
			OutputBox->AppendText(Environment::NewLine + gotoString(str));
		}
	}
	return;
}

void DSGrammarly::MyForm::DictionaryInputButton_Click(System::Object^ sender, System::EventArgs^ e) 
{
	string input = backtostring(DictionaryInputBox->Text);
	D1->SentenceMeaning(input, MeaningBox);
}

void DSGrammarly::MyForm::SynonymInputButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	string input = backtostring(DictionaryInputBox->Text);
	string word = "";
	for (int i=0; i<input.size()+1;i++)
	{
		if (input[i] == ' ' || input[i] == '.' || input[i] == '?' || input[i] == '!' || input[i] == '\0')
		{
			SynonymBox->AppendText(gotoString(word) + ": ");
			D1->find_syno(word, SynonymBox);
			SynonymBox->AppendText(Environment::NewLine);
			word = "";
		}
		else {
			word = word + input[i];
		}
	}
}

void DSGrammarly::MyForm::FindSynonymButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	string input = backtostring(InputBox->Text);
	Tabs->SelectedTab = Dictionary;
	DictionaryInputBox->Text = InputBox->Text;
	string word = "";
	for (int i = 0; i < input.size() + 1; i++)
	{
		if (input[i] == ' ' || input[i] == '.' || input[i] == '?' || input[i] == '!' || input[i] == '\0')
		{
			SynonymBox->AppendText(gotoString(word) + ": ");
			D1->find_syno(word, SynonymBox);
			SynonymBox->AppendText(Environment::NewLine);
			word = "";
		}
		else {
			word = word + input[i];
		}
	}
}
