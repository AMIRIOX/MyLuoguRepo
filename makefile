# To guard this love to the death.

VERSION = -std=c++20
# CXXFLAGS = -g3 -pipe -Wall -D_DEBUG -Wall -Werror -Wextra -pedantic -Wimplicit-fallthrough -Wsequence-point -Wswitch-default -Wswitch-unreachable -Wswitch-enum -Wstringop-truncation -Wbool-compare -Wtautological-compare -Wfloat-equal -Wshadow=global -Wpointer-arith -Wpointer-compare -Wcast-align -Wcast-qual -Wconversion -Wwrite-strings -Wdangling-else -Wlogical-op -finput-charset=utf-8 -fexec-charset=utf-8
CXXFLAGS = -pipe -Wall -D_DEBUG -Wall -Werror -Wextra -pedantic -Wimplicit-fallthrough -Wsequence-point -Wswitch-default -Wswitch-unreachable -Wswitch-enum -Wstringop-truncation -Wbool-compare -Wtautological-compare -Wfloat-equal -Wshadow=global -Wpointer-arith -Wpointer-compare -Wcast-align -Wcast-qual -Wconversion -Wwrite-strings -Wdangling-else -Wlogical-op -finput-charset=utf-8 -fexec-charset=utf-8
REHAB_PATH = rehab-241019
IS_WSL := $(shell grep -i -q "microsoft" /proc/version && echo "true" || echo "false")
TEMP = $(REHAB_PATH)/temp.cpp
OPTIONS = $(CXXFLAGS) $(VERSION)

rhb:
	$(CXX) $(TEMP) -o temp $(OPTIONS) && ./temp

rhbi:
	$(CXX) $(TEMP) -o temp $(OPTIONS) && ./temp < $(REHAB_PATH)/in.txt

rhbo:
	$(CXX) $(TEMP) -o temp $(OPTIONS) \
		&& echo "done:" && ./temp > $(REHAB_PATH)/out.txt && cat $(REHAB_PATH)/out.txt

%: %.cpp
	$(CXX) $< -o a.out $(OPTIONS) && ./a.out

filename := $(word 2, $(MAKECMDGOALS))

rgen:
	@if [ "$(filename)" != "" ]; then \
		cp $(TEMP) $(REHAB_PATH)/$(filename).cpp; \
		echo "[Rehab] Copied temp.cpp to $(REHAB_PATH)/$(filename).cpp"; \
	else \
		echo "Error: Please specify a target filename."; \
	fi

gen:
	@if [ "$(filename)" != "" ]; then \
		cp $(TEMP) $(filename).cpp; \
		echo "[Rehab] Copied temp.cpp to $(filename).cpp"; \
	else \
		echo "Error: Please specify a target filename."; \
	fi

cp:
ifeq ($(IS_WSL),true)
	cat $(TEMP) | clip.exe
else
	@echo "Not running in WSL."
endif


%:
	@:


