// -*- C++ -*-
/*!
 * @file  timedDoubleIn.cpp
 * @brief ModuleDescription
 * @date $Date$
 *
 * $Id$
 */

#include "timedDoubleIn.h"

// Module specification
// <rtc-template block="module_spec">
static const char* timeddoublein_spec[] =
  {
    "implementation_id", "timedDoubleIn",
    "type_name",         "timedDoubleIn",
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
timedDoubleIn::timedDoubleIn(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_timedDoubleInIn("timedDoubleIn", m_timedDoubleIn)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
timedDoubleIn::~timedDoubleIn()
{
}



RTC::ReturnCode_t timedDoubleIn::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("timedDoubleIn", m_timedDoubleInIn);
  
  // Set OutPort buffer
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t timedDoubleIn::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t timedDoubleIn::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t timedDoubleIn::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t timedDoubleIn::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t timedDoubleIn::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t timedDoubleIn::onExecute(RTC::UniqueId ec_id)
{
  if(m_timedDoubleInIn.isNew()){
    m_timedDoubleInIn.read();

    std::cout<<"入力された数字は"<<m_timedDoubleIn.data<<"です。"<<std::endl;

  }
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t timedDoubleIn::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t timedDoubleIn::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t timedDoubleIn::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t timedDoubleIn::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t timedDoubleIn::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void timedDoubleInInit(RTC::Manager* manager)
  {
    coil::Properties profile(timeddoublein_spec);
    manager->registerFactory(profile,
                             RTC::Create<timedDoubleIn>,
                             RTC::Delete<timedDoubleIn>);
  }
  
};


