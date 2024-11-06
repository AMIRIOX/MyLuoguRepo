# 

VERSION = -std=c++20
CXXFLAGS = -g3 -pipe -Wall -D_DEBUG -Wall -Werror -Wextra -pedantic -Wimplicit-fallthrough -Wsequence-point -Wswitch-default -Wswitch-unreachable -Wswitch-enum -Wstringop-truncation -Wbool-compare -Wtautological-compare -Wfloat-equal -Wshadow=global -Wpointer-arith -Wpointer-compare -Wcast-align -Wcast-qual -Wconversion -Wwrite-strings -Wdangling-else -Wlogical-op -finput-charset=utf-8 -fexec-charset=utf-8
REHAB_PATH = rehab-241019


rhb:
	$(CXX) $(REHAB_PATH)/temp.cpp -o temp $(VERSION) $(CXXFLAGS) && ./temp

rhbi:
	$(CXX) $(REHAB_PATH)/temp.cpp -o temp $(VERSION) $(CXXFLAGS) && ./temp < $(REHAB_PATH)/in.txt

rhbo:
	$(CXX) $(REHAB_PATH)/temp.cpp -o temp $(VERSION) $(CXXFLAGS) && ./temp > $(REHAB_PATH)/out.txt && cat $(REHAB_PATH)/out.txt

%: %.cpp
	$(CXX) $< -o a.out $(VERSION) $(CXXFLAGS) && ./a.out

filename := $(word 2, $(MAKECMDGOALS))

rgen:
	@if [ "$(filename)" != "" ]; then \
		cp $(REHAB_PATH)/temp.cpp $(REHAB_PATH)/$(filename).cpp; \
		echo "[Rehab] Copied temp.cpp to $(filename).cpp"; \
	else \
		echo "Error: Please specify a target filename."; \
	fi

%:
	@:


