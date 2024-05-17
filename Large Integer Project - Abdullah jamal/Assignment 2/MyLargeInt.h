#include<iostream>
#include <string>
using namespace std;

class LargeInteger {
private:
	short int* number;
	int length;
	int maxSize;
	void set_zero()
	{
		for (int i = 0; i < maxSize; i++)
			number[i] = 0;
	}

public:
	int starting_index()
	{
		return (maxSize - length);
	}
	LargeInteger(int size = 10)
	{
		maxSize = size;
		length = 0;
		number = new short int[maxSize];
		for (int i = 0; i < maxSize; i++)
			number[i] = 0;
	}
	LargeInteger(const LargeInteger& obj)
	{
		maxSize = obj.maxSize;
		length = obj.length;
		number = new short int[maxSize];
		for (int i = 0; i < maxSize; i++)
			this->number[i] = obj.number[i];
	}
	~LargeInteger()
	{
		if (number != NULL)
			delete[]number;
		number = NULL;
	}
	void delete_zeros()
	{
		int count = 0;
		for (int j = 0; j < maxSize; j++)
			if(number[j]==0) count++;
		if (count == maxSize)
		{
			return;
		}

		int i;
		for (i = 0; i < maxSize; i++)
			if (number[i] > 0)
				break;

		if (i > (maxSize - length))
		{
			int n = i - (maxSize - length);
			length -= n;
		}
	}
	bool set(string str)
	{
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] < 48 || str[i]>57)
			{
				length = 0;
				return 0;
			}
		}

		int count = 0;
		int b;
		for ( b = 0; b < str.length(); b++)
			if (int(str[b]) == 48) count++;
		if (count == str.length())
		{
			length = 1;
			number[0] = 0;
			return true;
		}
		if (maxSize < str.length())
		{
			maxSize = str.length();
		}
		delete[] number;
		number = new short int[maxSize];
		set_zero();
		length = str.length();

		int n;
		for (n = 0; n < str.length(); n++)
		{
			if (int(str[n]) != 48)
			{
				break;
			}
		}
		length -= n;

		for (int i = str.length() - 1, j = maxSize - 1; i >= n; i--, j--)
		{
			number[j] = (int(str[i]) - 48);
		}
		return 1;

	}
	void read(istream& in)
	{
		string num;
		in >> num;
		set(num);
	}
	void write(ostream& out)
	{
		for (int i = starting_index(); i < maxSize; i++)
			out << number[i];
	}
	LargeInteger operator+(const LargeInteger& obj)
	{
		if (length >= obj.length)
		{
			LargeInteger k(length + 1);
			int i = maxSize - 1;
			int j = obj.maxSize - 1;
			int v = k.maxSize - 1;
			bool yes = 0;
			for (; j >= (obj.maxSize - obj.length); j--, i--, v--)
			{
				if (obj.number[j] + number[i] + k.number[v] > 9)
				{
					k.number[v - 1] = int(obj.number[j] + number[i] + k.number[v]) / 10;
					k.number[v] = int(obj.number[j] + number[i] + k.number[v]) % 10;
					k.length++;
					yes = 1;

				}
				else
				{
					k.number[v] += obj.number[j] + number[i];
					k.length++;
					yes = 0;
				}


			}
			if (length == obj.length)
			{
				if (yes == 1)
					k.length++;
				return k;
			}
			for (int c = i; c >= (maxSize - length); c--, v--)
			{
				if ((number[c] + k.number[v]) > 9)
				{
					k.number[v - 1] = (number[c] + k.number[v]) / 10;
					k.number[v] = (number[c] + k.number[v]) % 10;
					k.length++;
					yes = 1;

				}
				else
				{
					k.number[v] += number[c];
					k.length++;
					yes = 0;
				}

			}
			if (yes == 1)
				k.length++;
			return k;
		}
		else if (length < obj.length)
		{
			LargeInteger k(obj.length + 1);
			int j = maxSize - 1;
			int i = obj.maxSize - 1;
			int v = k.maxSize - 1;
			bool yes = 0;
			for (; j >= (maxSize - length); j--, i--, v--)
			{
				if (number[j] + obj.number[i] + k.number[v] > 9)
				{
					k.number[v - 1] = int(number[j] + obj.number[i] + k.number[v]) / 10;
					k.number[v] = int(number[j] + obj.number[i] + k.number[v]) % 10;
					k.length++;
					yes = 1;

				}
				else
				{
					k.number[v] += number[j] + obj.number[i];
					k.length++;
					yes = 0;
				}


			}
			for (int c = i; c >= (obj.maxSize - obj.length); c--, v--)
			{
				if ((obj.number[c] + k.number[v]) > 9)
				{
					k.number[v - 1] = (obj.number[c] + k.number[v]) / 10;
					k.number[v] = (obj.number[c] + k.number[v]) % 10;
					k.length++;
					yes = 1;

				}
				else
				{
					k.number[v] += obj.number[c];
					k.length++;
					yes = 0;
				}

			}
			if (yes == 1)
				k.length++;
			return k;
		}

	}

	LargeInteger operator-(const LargeInteger& obj)
	{
		if (length > obj.length)
		{
			LargeInteger k(length);
			int i = maxSize - 1;
			int j = obj.maxSize - 1;
			int v = k.maxSize - 1;
			short int* arr;
			arr = new short int[maxSize];
			for (int i = 0; i < maxSize; i++)
			{
				arr[i] = number[i];
			}
			for (; j >= (obj.maxSize - obj.length); j--, i--, v--)
			{
				if ((arr[i] - obj.number[j]) < 0)
				{
					arr[i] += 10;
					int m = i;
					while (true)
					{
						if (arr[m - 1] > 0)
						{
							arr[m - 1]--;
							break;
						}
						else
						{
							arr[m - 1] = 9;
						}

						m--;
					}
					k.number[v] = (arr[i] - obj.number[j]);
					k.length++;
				}
				else
				{
					k.number[v] = (arr[i] - obj.number[j]);
					k.length++;

				}

			}
			for (int c = i; c >= (maxSize - length); c--, v--)
			{
				k.number[v] = arr[c];
				k.length++;
			}
			k.delete_zeros();
			return k;
		}
		else if (length < obj.length)
		{
			LargeInteger k(obj.length);
			int j = maxSize - 1;
			int i = obj.maxSize - 1;
			int v = k.maxSize - 1;
			short int* arr;
			arr = new short int[obj.maxSize];
			for (int i = 0; i < obj.maxSize; i++)
			{
				arr[i] = obj.number[i];
			}
			for (; j >= (maxSize - length); j--, i--, v--)
			{
				if ((arr[i] - number[j]) < 0)
				{
					arr[i] += 10;
					int m = i;
					while (true)
					{
						if (arr[m - 1] > 0)
						{
							arr[m - 1]--;
							break;
						}
						else
						{
							arr[m - 1] = 9;
						}

						m--;
					}
					k.number[v] = (arr[i] - number[j]);
					k.length++;
				}
				else
				{
					k.number[v] = (arr[i] - number[j]);
					k.length++;

				}

			}
			for (int c = i; c >= (obj.maxSize - obj.length); c--, v--)
			{
				k.number[v] = arr[c];
				k.length++;
			}
			k.delete_zeros();
			return k;
		}
		else
		{
			int countt = 0;
			for (int i = maxSize - length, j=obj.maxSize- obj.length; i < maxSize; i++,j++)
			{
				if (number[i] == obj.number[j])
					countt++;
			}
			if (countt == length)
			{
				LargeInteger k(1);
				k.length = 1;
				number[0] = 0;
				return k;
			}
			int different = 0;
			for (int i = maxSize - length, j = obj.maxSize - obj.length; i < maxSize; i++,j++)
			{
				if (number[i] > obj.number[j])
				{
					different = 1;
					break;
				}
				else if(number[i] < obj.number[j])
				{
					break;
				}
			}

			if (different==1)
			{
				LargeInteger k(length);
				int i = maxSize - 1;
				int j = obj.maxSize - 1;
				int v = k.maxSize - 1;
				short int* arr;
				arr = new short int[maxSize];
				for (int i = 0; i < maxSize; i++)
				{
					arr[i] = number[i];
				}
				for (; j >= (obj.maxSize - obj.length); j--, i--, v--)
				{
					if ((arr[i] - obj.number[j]) < 0)
					{
						arr[i] += 10;
						arr[i - 1]--;
						k.number[v] = (arr[i] - obj.number[j]);
						k.length++;
					}
					else
					{
						k.number[v] = (arr[i] - obj.number[j]);
						k.length++;

					}

				}
				for (int c = i; c >= (maxSize - length); c--, v--)
				{
					k.number[v] = arr[c];
					k.length++;
				}
				k.delete_zeros();
				return k;
			}
			else
			{
				LargeInteger k(obj.length);
				int j = maxSize - 1;
				int i = obj.maxSize - 1;
				int v = k.maxSize - 1;
				short int* arr;
				arr = new short int[obj.maxSize];
				for (int i = 0; i < obj.maxSize; i++)
				{
					arr[i] = obj.number[i];
				}
				for (; j >= (maxSize - length); j--, i--, v--)
				{
					if ((arr[i] - number[j]) < 0)
					{
						arr[i] += 10;
						arr[i - 1]--;
						k.number[v] = (arr[i] - number[j]);
						k.length++;
					}
					else
					{
						k.number[v] = (arr[i] - number[j]);
						k.length++;

					}

				}
				for (int c = i; c >= (obj.maxSize - obj.length); c--, v--)
				{
					k.number[v] = arr[c];
					k.length++;
				}
				k.delete_zeros();
				return k;
			}

		}
	}

	LargeInteger operator*(const LargeInteger& obj)
	{
		int checkAll = 0;
		for (int i = 0; i < maxSize; i++)
		{
			if (number[i] == 0) checkAll++;
		}
		if (checkAll == maxSize)
		{
			LargeInteger k(1);
			k.length = 1;
			k.number[0] = 0;
			return k;
		}
		else
		{
			checkAll = 0;
			for (int i = 0; i < obj.maxSize; i++)
			{
				if (obj.number[i] == 0) checkAll++;
			}
			if (checkAll == maxSize)
			{
				LargeInteger k(1);
				k.length = 1;
				k.number[0] = 0;
				return k;
			}

		}
		LargeInteger* k = new LargeInteger[obj.length];
		for (int i = 0; i < obj.length; i++)
		{
			k[i].maxSize = maxSize + obj.maxSize;	
			k[i].~LargeInteger();
			k[i].number = new short int[k[i].maxSize];
			k[i].set_zero();
		}
		int i = maxSize - 1;
		int j = obj.maxSize - 1;
		int v = (maxSize + obj.maxSize) - 1;
		int o = 0;
		int zeros = 0;
		int carry = 0;
		for (; i >= (maxSize - length); i--, v--)
		{
			if ((number[i] * obj.number[j] + carry) > 9)
			{
				k[o].number[v] = (number[i] * obj.number[j] + carry) % 10;
				carry = (number[i] * obj.number[j] + carry) / 10;
				k[o].length++;
				if (i <= (maxSize - length))
				{
					k[o].number[v - 1] = carry;
					k[o].length++;
					carry = 0;
					if (j <= (obj.maxSize - obj.length))
					{
						break;
					}
					o++;
					j--;
					zeros++;
					int count_zero = zeros;
					v = (maxSize + obj.maxSize) - 1;
					i = maxSize - 1 + 1;
					int b;
					for (b = v; count_zero > 0; b--, count_zero--)
					{
						k[o].number[b] = 0;
						k[o].length++;
					}
					v = b + 1;

				}

			}
			else
			{
				k[o].number[v] = number[i] * obj.number[j] + carry;
				k[o].length++;
				carry = 0;
				if (j <= (obj.maxSize - obj.length) && i <= (maxSize - length))
				{
					break;
				}
				if (i <= (maxSize - length))
				{
					carry = 0;
					o++;
					j--;
					zeros++;
					int count_zero = zeros;
					v = (maxSize + obj.maxSize) - 1;
					i = maxSize - 1 + 1;
					int b;
					for (b = v; count_zero > 0; b--, count_zero--)
					{
						k[o].number[b] = 0;
						k[o].length++;
					}
					v = b + 1;


				}
			}

		}
		cout << endl;
		LargeInteger T(maxSize + obj.maxSize);
		for (int s = 0; s < obj.length; s++)
		{
			T = T + k[s];
		}
		cout << endl;

		return T;

	}

	LargeInteger operator=(const LargeInteger& obj)
	{
		if (number != NULL)
			delete[] number;
		maxSize = obj.maxSize;
		length = obj.length;
		number = new short int[maxSize];
		for (int i = 0; i < maxSize; i++)
			this->number[i] = obj.number[i];

		return *this;
	}

	bool operator==(const LargeInteger& obj)
	{
		if (length != obj.length)
			return false;

		int i = maxSize - 1;
		int j = obj.maxSize - 1;
		for (; i >= (maxSize - length); i--, j--)
		{
			if (number[i] != obj.number[j])
				return false;
		}
		return true;
	}
	bool operator < (const LargeInteger& obj)
	{
		if (length > obj.length)
			return false;
		if (length < obj.length)
			return true;

		int i = maxSize - length;
		int j = obj.maxSize - obj.length;
		int counter = 0;
		for (; i < maxSize; i++, j++)
		{
			if (number[i] > obj.number[j])
				return false;
			else  if (number[i] < obj.number[j])
				return true;
			if (number[i] == obj.number[j])
				counter++;
		}
		if (counter == length)
			return false;
		return true;

	}

	bool operator > (const LargeInteger& obj)
	{
		if (length < obj.length)
			return false;
		if (length > obj.length)
			return true;

		int i = maxSize - length;
		int j = obj.maxSize - obj.length;
		int counter = 0;
		for (; i < maxSize; i++, j++)
		{
			if (number[i] < obj.number[j])
				return false;
			else if (number[i] > obj.number[j])
				return true;
			if (number[i] == obj.number[j])
				counter++;
		}
		if (counter == length)
			return false;
		return true;

	}



};