// -*- C++ -*-
/*!
 * @file  timedDoubleOut.cpp
 * @brief ModuleDescription
 * @date $Date$
 *
 * $Id$
 */

#include "timedDoubleOut.h"

// Module specification
// <rtc-template block="module_spec">
static const char* timeddoubleout_spec[] =
  {
    "implementation_id", "timedDoubleOut",
    "type_name",         "timedDoubleOut",
    "description",       "ModuleDescription",
    "version",           "1.0.0",
    "vendor",            "VenderName",
    "category",          "Category",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
timedDoubleOut::timedDoubleOut(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_timedDoubleOutOut("timedDoubleOut", m_timedDoubleOut)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
timedDoubleOut::~timedDoubleOut()
{
}



RTC::ReturnCode_t timedDoubleOut::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  
  // Set OutPort buffer
  addOutPort("timedDoubleOut", m_timedDoubleOutOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t timedDoubleOut::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t timedDoubleOut::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t timedDoubleOut::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t timedDoubleOut::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t timedDoubleOut::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t timedDoubleOut::onExecute(RTC::UniqueId ec_id)
{
  double num;

  std::cout<<"数字を入力してください。"<<std::endl;
  std::cin>>num;
  std::cout<<"入力された数字は"<<num<<"です。"<<std::endl;

  m_timedDoubleOut.data=num;
  m_timedDoubleOutOut.write();

  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t timedDoubleOut::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t timedDoubleOut::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t timedDoubleOut::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t timedDoubleOut::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t timedDoubleOut::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void timedDoubleOutInit(RTC::Manager* manager)
  {
    coil::Properties profile(timeddoubleout_spec);
    manager->registerFactory(profile,
                             RTC::Create<timedDoubleOut>,
                             RTC::Delete<timedDoubleOut>);
  }
  
};


