#include "NESL.h"
#include "States.h"
#include <iostream>
int main()
{
	HBV::bit_vector veca,vecb;
	veca.set(1, true);
	veca.set(3, true);
	vecb.set(1, true);
	auto vecab = HBV::compose(HBV::and_op, veca, vecb);

	HBV::for_each(vecab, [](uint32_t id) {
		std::cout << id << std::endl;
	});

	ESL::states st;
	st.add<int>(1);
	
	std::cout << *st.get<int>() << std::endl;
    return 0;
}

