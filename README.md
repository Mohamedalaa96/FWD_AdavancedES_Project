# FWD_AdavancedES_Project
EG FWD Advanced Embedded Systems Nanodegree Projects

## Naming Convention
---
- ProjectName : Project_Name

- FolderName
ModuleName_FileName

-  ModuleName_FunctionName(parameterName)
-  localVariable (init with lower case)

-  MODULENAME_MACRO_OBJECT
ModuleName_MacroFunctionName(Parameter)


- typedef <primitive-type> ModuleName_TypeNameType; (postfix with "Type")


- struct
{
   <AnyType> firstMember;
   <AnyType> secondMember;
   <AnyType> thirdMember;
   <AnyType> fourthMember;
}

- enum
{
   MODULENAME_FIRST_MEMBER = 0,
   MODULENAME_SECOND_MEMBER,
   MODULENAME_THIRD_MEMBER
}

## Layered Architecture
___
### App Folder
Contains the Application layer source files

### Common Folder
Common between all modules (std types, platform types , compiler.h)

### Config Folder
contain configuration files
#### Include folder
It has all the .h files +Cfg
#### source files 
+LCfg "Link time configuration"
### MCAL 
MCU Abstraction Layer contains the following
#### Include folder
It has all the .h files
#### source files 

