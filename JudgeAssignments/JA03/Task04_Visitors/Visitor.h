#pragma once
#include <string>
#include <functional>

class Visitor
{
private:
	std::string id;
	std::string name;
	int age;

public:
	Visitor() {}
	Visitor(std::string id, std::string name, int age)
		: id(id), name(name), age(age)
	{
	}

	std::string getId() const
	{
		return this->id;
	}

	std::string getName() const
	{
		return this->name;
	}

	int getAge() const
	{
		return this->age;
	}

	//bool operator==(const Visitor& other)
	//{
	//	return this->id == other.id;
	//}

	/*bool operator!=(const Visitor& other)
	{
		return !(*this == other);
	}*/
};

//bool operator==(const Visitor& firstVisitor, const Visitor& secondVisitor)
//{
//	return firstVisitor.getId() == secondVisitor.getId();
//}
//
//template <>
//struct std::hash<Visitor>
//{
//	size_t operator()(Visitor const & v) const noexcept
//	{
//		return (
//			(51 + std::hash<int>()(v.getAge())) * 51
//			+ std::hash<std::string>()(v.getName())
//			);
//	}
//};