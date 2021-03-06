/* Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
   file Copyright.txt or https://cmake.org/licensing for details.  */
#include "cmCustomCommand.h"

#include "cmMakefile.h"

#include <utility>

cmCustomCommand::cmCustomCommand(cmMakefile const* mf,
                                 std::vector<std::string> outputs,
                                 std::vector<std::string> byproducts,
                                 std::vector<std::string> depends,
                                 cmCustomCommandLines commandLines,
                                 const char* comment,
                                 const char* workingDirectory)
  : Outputs(std::move(outputs))
  , Byproducts(std::move(byproducts))
  , Depends(std::move(depends))
  , CommandLines(std::move(commandLines))
  , Comment(comment ? comment : "")
  , WorkingDirectory(workingDirectory ? workingDirectory : "")
  , HaveComment(comment != nullptr)
{
  if (mf) {
    this->Backtrace = mf->GetBacktrace();
  }
}

const std::vector<std::string>& cmCustomCommand::GetOutputs() const
{
  return this->Outputs;
}

const std::vector<std::string>& cmCustomCommand::GetByproducts() const
{
  return this->Byproducts;
}

const std::vector<std::string>& cmCustomCommand::GetDepends() const
{
  return this->Depends;
}

const cmCustomCommandLines& cmCustomCommand::GetCommandLines() const
{
  return this->CommandLines;
}

const char* cmCustomCommand::GetComment() const
{
  const char* no_comment = nullptr;
  return this->HaveComment ? this->Comment.c_str() : no_comment;
}

void cmCustomCommand::AppendCommands(const cmCustomCommandLines& commandLines)
{
  this->CommandLines.insert(this->CommandLines.end(), commandLines.begin(),
                            commandLines.end());
}

void cmCustomCommand::AppendDepends(const std::vector<std::string>& depends)
{
  this->Depends.insert(this->Depends.end(), depends.begin(), depends.end());
}

bool cmCustomCommand::GetEscapeOldStyle() const
{
  return this->EscapeOldStyle;
}

void cmCustomCommand::SetEscapeOldStyle(bool b)
{
  this->EscapeOldStyle = b;
}

bool cmCustomCommand::GetEscapeAllowMakeVars() const
{
  return this->EscapeAllowMakeVars;
}

void cmCustomCommand::SetEscapeAllowMakeVars(bool b)
{
  this->EscapeAllowMakeVars = b;
}

cmListFileBacktrace const& cmCustomCommand::GetBacktrace() const
{
  return this->Backtrace;
}

cmCustomCommand::ImplicitDependsList const&
cmCustomCommand::GetImplicitDepends() const
{
  return this->ImplicitDepends;
}

void cmCustomCommand::SetImplicitDepends(ImplicitDependsList const& l)
{
  this->ImplicitDepends = l;
}

void cmCustomCommand::AppendImplicitDepends(ImplicitDependsList const& l)
{
  this->ImplicitDepends.insert(this->ImplicitDepends.end(), l.begin(),
                               l.end());
}

bool cmCustomCommand::GetUsesTerminal() const
{
  return this->UsesTerminal;
}

void cmCustomCommand::SetUsesTerminal(bool b)
{
  this->UsesTerminal = b;
}

bool cmCustomCommand::GetCommandExpandLists() const
{
  return this->CommandExpandLists;
}

void cmCustomCommand::SetCommandExpandLists(bool b)
{
  this->CommandExpandLists = b;
}

const std::string& cmCustomCommand::GetDepfile() const
{
  return this->Depfile;
}

void cmCustomCommand::SetDepfile(const std::string& depfile)
{
  this->Depfile = depfile;
}

const std::string& cmCustomCommand::GetJobPool() const
{
  return this->JobPool;
}

void cmCustomCommand::SetJobPool(const std::string& job_pool)
{
  this->JobPool = job_pool;
}
