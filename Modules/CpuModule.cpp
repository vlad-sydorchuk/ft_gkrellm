//
// Created by Illia Lukianov on 11/12/17.
//

#include "CpuModule.h"
#include <mach/mach_init.h>
#include <mach/mach_error.h>
#include <mach/mach_host.h>
#include <mach/vm_map.h>
#include <sstream>
#include <iomanip>
#include <thread>

static unsigned long long _previousTotalTicks = 0;
static unsigned long long _previousIdleTicks = 0;

CpuModule::CpuModule(CpuModule const & copy) {
	*this = copy;
}

CpuModule & CpuModule::operator=(CpuModule const &copy) {
	this->info = copy.info;
	this->moduleName = copy.moduleName;
	return *this;
}

float CalculateCPULoad(unsigned long long idleTicks, unsigned long long totalTicks)
{
	unsigned long long totalTicksSinceLastTime = totalTicks-_previousTotalTicks;
	unsigned long long idleTicksSinceLastTime  = idleTicks-_previousIdleTicks;
	float ret = ((totalTicksSinceLastTime > 0) ? ((float)idleTicksSinceLastTime)/totalTicksSinceLastTime : 0);
	_previousTotalTicks = totalTicks;
	_previousIdleTicks  = idleTicks;
	return ret;
}

float GetCPULoad()
{
	host_cpu_load_info_data_t cpuinfo;
	mach_msg_type_number_t count = HOST_CPU_LOAD_INFO_COUNT;
	if (host_statistics(mach_host_self(), HOST_CPU_LOAD_INFO, (host_info_t)&cpuinfo, &count) == KERN_SUCCESS)
	{
		unsigned long long totalTicks = 0;
		for(int i=0; i<CPU_STATE_MAX; i++) totalTicks += cpuinfo.cpu_ticks[i];
		return CalculateCPULoad(cpuinfo.cpu_ticks[CPU_STATE_IDLE], totalTicks);
	}
	else return -1.0f;
}

CpuModule::CpuModule() : AInfo<std::string*>::AInfo("CpuModule") {
	info = new std::string[4];
	updateModule();
}

CpuModule::~CpuModule() {

}

void CpuModule::updateModule() {
	FILE *in;
	char buffer[BUFFERLEN];
	if (!(in = popen("sysctl -n machdep.cpu.brand_string", "r"))) {
		throw std::exception();
	}
	while (fgets(buffer, sizeof(buffer), in) != NULL) {
		info[0] = std::string(buffer);
		break ;
	}
	pclose(in);
	std::stringstream stream;

	float tmp = (GetCPULoad() * 100);
	stream << std::fixed << std::setprecision(2) << tmp;
	info[1] = "Cpu Idle: ";
	info[1] += stream.str();
	info[1] += " %%";
	tmp = (tmp - 100) * -1;
	stream.str("");
	stream << std::fixed << std::setprecision(2) << tmp;
	info[2] = "Cpu Load: ";
	info[2] += stream.str();
	info[2] += " %%";
	stream.str("");
	stream << std::thread::hardware_concurrency();
	info[3] = "Cpu Core: ";
	info[3] += stream.str();
}
