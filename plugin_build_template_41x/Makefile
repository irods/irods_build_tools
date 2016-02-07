MSITEST_ONE = msitest_one
#MSITEST_TWO = msitest_two
#MSITEST_THREE = msitest_three

MAKEFLAGS += --no-print-directory

LIBS = \
       $(MSITEST_ONE) \
#       $(MSITEST_TWO) \
#       $(MSITEST_THREE) 

.PHONY: all $(LIBS) clean
all: $(LIBS)

$(LIBS):
	@$(MAKE) -C $@;

clean:
	@$(MAKE) -C $(MSITEST_ONE) clean;
#	@$(MAKE) -C $(MSITEST_TWO) clean;
#	@$(MAKE) -C $(MSITEST_THREE) clean;
