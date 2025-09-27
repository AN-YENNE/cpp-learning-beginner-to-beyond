##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=15_Inheritance_Challenge
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :=C:/ANY/31_CPP/cpp-learning-beginner-to-beyond/Workspace
ProjectPath            :=C:/ANY/31_CPP/cpp-learning-beginner-to-beyond/Workspace/15_Inheritance_Challenge
IntermediateDirectory  :=../build-$(WorkspaceConfiguration)/15_Inheritance_Challenge
OutDir                 :=$(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=SHJETYM
Date                   :=27/09/2025
CodeLitePath           :=C:/Tools/CodeLite
MakeDirCommand         :=mkdir
LinkerName             :=C:/Tools/mingw64/bin/g++.exe
SharedObjectLinkerName :=C:/Tools/mingw64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputDirectory        :=C:/ANY/31_CPP/cpp-learning-beginner-to-beyond/Workspace/build-$(WorkspaceConfiguration)/bin
OutputFile             :=..\build-$(WorkspaceConfiguration)\bin\$(ProjectName).exe
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
RcCmpOptions           := 
RcCompilerName         :=C:/Tools/mingw64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overridden using an environment variable
##
AR       := C:/Tools/mingw64/bin/ar.exe -r
CXX      := C:/Tools/mingw64/bin/g++.exe
CC       := C:/Tools/mingw64/bin/gcc.exe
CXXFLAGS :=  -gdwarf-2 -O0 -Wall $(Preprocessors)
CFLAGS   :=  -gdwarf-2 -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/Tools/mingw64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Tools\CodeLite
Objects0=$(IntermediateDirectory)/up_up_up_Section15_Section15_ChallengeSolution_Savings_Account.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_up_Section15_Section15_ChallengeSolution_Checking_Account.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_up_Section15_Section15_ChallengeSolution_Trust_Account.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_up_Section15_Section15_ChallengeSolution_Account.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_up_Section15_Section15_ChallengeSolution_main.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_up_Section15_Section15_ChallengeSolution_Account_Util.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@if not exist "$(IntermediateDirectory)" $(MakeDirCommand) "$(IntermediateDirectory)"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@if not exist "$(IntermediateDirectory)" $(MakeDirCommand) "$(IntermediateDirectory)"
	@if not exist "$(OutputDirectory)" $(MakeDirCommand) "$(OutputDirectory)"

$(IntermediateDirectory)/.d:
	@if not exist "$(IntermediateDirectory)" $(MakeDirCommand) "$(IntermediateDirectory)"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/up_up_up_Section15_Section15_ChallengeSolution_Savings_Account.cpp$(ObjectSuffix): ../../../Section15/Section15/ChallengeSolution/Savings_Account.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/ANY/31_CPP/Section15/Section15/ChallengeSolution/Savings_Account.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_up_Section15_Section15_ChallengeSolution_Savings_Account.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_up_Section15_Section15_ChallengeSolution_Savings_Account.cpp$(PreprocessSuffix): ../../../Section15/Section15/ChallengeSolution/Savings_Account.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_up_Section15_Section15_ChallengeSolution_Savings_Account.cpp$(PreprocessSuffix) ../../../Section15/Section15/ChallengeSolution/Savings_Account.cpp

$(IntermediateDirectory)/up_up_up_Section15_Section15_ChallengeSolution_Checking_Account.cpp$(ObjectSuffix): ../../../Section15/Section15/ChallengeSolution/Checking_Account.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/ANY/31_CPP/Section15/Section15/ChallengeSolution/Checking_Account.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_up_Section15_Section15_ChallengeSolution_Checking_Account.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_up_Section15_Section15_ChallengeSolution_Checking_Account.cpp$(PreprocessSuffix): ../../../Section15/Section15/ChallengeSolution/Checking_Account.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_up_Section15_Section15_ChallengeSolution_Checking_Account.cpp$(PreprocessSuffix) ../../../Section15/Section15/ChallengeSolution/Checking_Account.cpp

$(IntermediateDirectory)/up_up_up_Section15_Section15_ChallengeSolution_Trust_Account.cpp$(ObjectSuffix): ../../../Section15/Section15/ChallengeSolution/Trust_Account.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/ANY/31_CPP/Section15/Section15/ChallengeSolution/Trust_Account.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_up_Section15_Section15_ChallengeSolution_Trust_Account.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_up_Section15_Section15_ChallengeSolution_Trust_Account.cpp$(PreprocessSuffix): ../../../Section15/Section15/ChallengeSolution/Trust_Account.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_up_Section15_Section15_ChallengeSolution_Trust_Account.cpp$(PreprocessSuffix) ../../../Section15/Section15/ChallengeSolution/Trust_Account.cpp

$(IntermediateDirectory)/up_up_up_Section15_Section15_ChallengeSolution_Account.cpp$(ObjectSuffix): ../../../Section15/Section15/ChallengeSolution/Account.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/ANY/31_CPP/Section15/Section15/ChallengeSolution/Account.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_up_Section15_Section15_ChallengeSolution_Account.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_up_Section15_Section15_ChallengeSolution_Account.cpp$(PreprocessSuffix): ../../../Section15/Section15/ChallengeSolution/Account.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_up_Section15_Section15_ChallengeSolution_Account.cpp$(PreprocessSuffix) ../../../Section15/Section15/ChallengeSolution/Account.cpp

$(IntermediateDirectory)/up_up_up_Section15_Section15_ChallengeSolution_main.cpp$(ObjectSuffix): ../../../Section15/Section15/ChallengeSolution/main.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/ANY/31_CPP/Section15/Section15/ChallengeSolution/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_up_Section15_Section15_ChallengeSolution_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_up_Section15_Section15_ChallengeSolution_main.cpp$(PreprocessSuffix): ../../../Section15/Section15/ChallengeSolution/main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_up_Section15_Section15_ChallengeSolution_main.cpp$(PreprocessSuffix) ../../../Section15/Section15/ChallengeSolution/main.cpp

$(IntermediateDirectory)/up_up_up_Section15_Section15_ChallengeSolution_Account_Util.cpp$(ObjectSuffix): ../../../Section15/Section15/ChallengeSolution/Account_Util.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/ANY/31_CPP/Section15/Section15/ChallengeSolution/Account_Util.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_up_Section15_Section15_ChallengeSolution_Account_Util.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_up_Section15_Section15_ChallengeSolution_Account_Util.cpp$(PreprocessSuffix): ../../../Section15/Section15/ChallengeSolution/Account_Util.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_up_Section15_Section15_ChallengeSolution_Account_Util.cpp$(PreprocessSuffix) ../../../Section15/Section15/ChallengeSolution/Account_Util.cpp

##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


