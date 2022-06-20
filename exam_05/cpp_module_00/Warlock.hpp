#ifndef WARLOCK_HPP
# define WARLOCK_HPP

#include <string>
#include <iostream>

class Warlock {

	private:
		std::string _name;
		std::string _title;

		Warlock();
		Warlock( Warlock const &copy );
		Warlock &operator=(Warlock const &right);
	
	public:
		Warlock (std::string const name, std::string const title);
		virtual ~Warlock();

		const std::string &getName() const;
		const std::string &getTitle() const;

		void setTitle(std::string const title);

		void introduce() const;
};

#endif
