TARGETS := main shared.so

all: $(TARGETS)

clean:
	rm -f $(TARGETS)

main: main.cc
	$(CXX) $< -o $@ -ldl


shared.so: shared.cc
	$(CXX) $< -o $@ -fPIC -shared

.PHONY: all clean
