TLD := /home/cassion/projects/rpg
OD := $(TLD)/obj
SD := $(TLD)/src
ALL := $(wildcard $(SD)*.cc)
SRCS := $(subst main.cc,,$(ALL))
SRCS += $(SD)/main.cc
OBJS := $(SRCS:.cc=.o)

$(OD)/%.o: $(SD)/%.cc
	g++ -c $< -o $@

rpg.bin: $(OBJS)
	g++ -o $@ $(SD)/main.o
