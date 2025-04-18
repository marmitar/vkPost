#pragma once

#include "vulkan_include.hpp"

#include "vkfuncs.hpp"

#define FORVKFUNC(func) PFN_vk##func func = nullptr;

namespace vkPost
{

    struct InstanceDispatch
    {
        VK_INSTANCE_FUNCS
    };

    struct DeviceDispatch
    {
        VK_DEVICE_FUNCS
    };

    void fillDispatchTableInstance(VkInstance instance, PFN_vkGetInstanceProcAddr gipa, InstanceDispatch* table);
    void fillDispatchTableDevice(VkDevice device, PFN_vkGetDeviceProcAddr gdpa, DeviceDispatch* table);

} // namespace vkPost

#undef FORVKFUNC
#undef VK_INSTANCE_FUNCS
#undef VK_DEVICE_FUNCS
