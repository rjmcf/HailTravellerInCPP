CC=g++
IDIR=src/header
SDIR=src/impl
ODIR=src/obj
TSDIR=test/impl
TODIR=test/obj
CFLAGS=-I $(IDIR)

GOOGLELDFLAGS=-lgtest -lgtest_main

# Add object file names here
_OBJ = main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.cpp 
	$(CC) -c -o $@ $< $(CFLAGS)

# Add test object file names here
_TEST = example_test.o
TEST = $(patsubst %,$(TODIR)/%,$(_TEST))

$(TODIR)/%.o: $(TSDIR)/%.cpp 
	$(CC) -c -o $@ $< $(CFLAGS)

	
main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	
test: $(TEST)
	$(CC) -o $@ $^ $(CFLAGS) $(GOOGLELDFLAGS)
	
.PHONY : runtest
runtest : 
	./$< --gtest_output="xml:TestResults.xml"
	
clean:
	rm -f $(ODIR)/*.o
	rm -f $(TODIR)/*.o
