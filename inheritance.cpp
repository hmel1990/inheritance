#include <iostream>
#include <string>

using namespace std;

class Student {
protected:
	string name;
	string surname;
	int age;
	double average_rating;

public:
	void set_name(const string& name)
	{
		this->name = name;
	}

	string get_name() const
	{
		return name;
	}

	void set_surname(const string& surname)
	{
		this->surname = surname;
	}

	string get_surname() const
	{
		return surname;
	}

	void set_age(const int& age)
	{
		if (age > 16 && age < 100)
		{
			this->age = age;
		}
	}

	int get_age() const
	{
		return age;
	}

	void set_average_rating(const int& average_rating)
	{
		if (average_rating > 0 && average_rating <= 12)
		{
			this->average_rating = average_rating;
		}
	}

	int get_average_rating() const
	{
		return average_rating;
	}

	Student() : Student("Maxim", "Khmelenko", 34, 12) {}

	Student(string name, string surname, int age, double average_rating)
	{
		set_name(name);
		set_surname(surname);
		set_age(age);
		set_average_rating(average_rating);
	}

	~Student() {}

	Student(const Student& original)							//конструктор копирования
	{
		name = original.name;
		surname = original.surname;
		set_age(original.age);
		set_average_rating(original.average_rating);			// на всякий случай делаем проверку на дипазон чере сеттер
	}

	void Print()
	{
		cout << this->name << "\n" << this->surname << "\n" << this->age << "\n" << this->average_rating << "\n";

	}
};

class Aspirant : public Student
{
private:
	string topic;
public:
	void set_topic(const string& topic)
	{
		this->topic = topic;
	}

	string get_topic() const
	{
		return topic;
	}

	Aspirant() : Aspirant("hadron collider") {}

	Aspirant(string topic)
	{
		set_topic(topic);
	}

	void Print()
	{

		cout << this->name << "\n" << this->surname << "\n" << this->age << "\n" << this->average_rating << "\n" << this->topic << "\n";
	}

	Aspirant(const Aspirant& original)							//конструктор копирования
	{
		topic = original.topic;
	}
};

int main()
{
	//Student st;
	//st.Print();

	Aspirant asp;
	asp.Print();

}