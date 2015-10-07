// Header file for clib.s output routines
#ifndef YAKK_H
#define YAKK_H

#define TASKNUMBER 4
#define true 1
#define false 0
#define NULL 0

typedef char bool;
typedef struct taskBlock *TCBptr;//struct pointer for TCB's and lists
enum task_st {ready_st, delayed_st};
typedef struct taskBlock{//TCB data structure
  void * SPtr;
  void * nextInst;
  enum task_st state;
  int priority;
  int tickDelay;
//  TCBptr prevTCB = NULL;
//  TCBptr nextTCB = NULL;
  TCBptr prevTCB;
  TCBptr nextTCB;
} TCB;



//TCBptr currentTask;
TCBptr readyTask;
TCBptr YKReadyList;//linked list of ready tasks
TCBptr YKSuspList;//linked list of Suspended tasks
TCBptr YKAvailList;//list of available tasks 
TCB YKTCBArray[TASKNUMBER+1];
int nestedDepth = 0;
int idleCount = 0;
int contextSwitchNum = 0;

#endif