//* This file is part of the MOOSE framework
//* https://mooseframework.inl.gov
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "raccoonxTestApp.h"
#include "raccoonxApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
raccoonxTestApp::validParams()
{
  InputParameters params = raccoonxApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

raccoonxTestApp::raccoonxTestApp(InputParameters parameters) : MooseApp(parameters)
{
  raccoonxTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

raccoonxTestApp::~raccoonxTestApp() {}

void
raccoonxTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  raccoonxApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"raccoonxTestApp"});
    Registry::registerActionsTo(af, {"raccoonxTestApp"});
  }
}

void
raccoonxTestApp::registerApps()
{
  registerApp(raccoonxApp);
  registerApp(raccoonxTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
raccoonxTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  raccoonxTestApp::registerAll(f, af, s);
}
extern "C" void
raccoonxTestApp__registerApps()
{
  raccoonxTestApp::registerApps();
}
