#include "Harl.hpp"

int	main(void)
{
	Harl	h = Harl();

	h.complain("INFO");
	h.complain("NOTHING");
	h.complain("ERROR");
	h.complain("DEBUG");
	h.complain("WOW");
	h.complain("WARNING");
}
