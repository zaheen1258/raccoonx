#include "raccoonxApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
raccoonxApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

raccoonxApp::raccoonxApp(InputParameters parameters) : MooseApp(parameters)
{
  raccoonxApp::registerAll(_factory, _action_factory, _syntax);
}

raccoonxApp::~raccoonxApp() {}

void
raccoonxApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAllObjects<raccoonxApp>(f, af, syntax);
  Registry::registerObjectsTo(f, {"raccoonxApp"});
  Registry::registerActionsTo(af, {"raccoonxApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
raccoonxApp::registerApps()
{
  registerApp(raccoonxApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
raccoonxApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  raccoonxApp::registerAll(f, af, s);
}
extern "C" void
raccoonxApp__registerApps()
{
  raccoonxApp::registerApps();
}
