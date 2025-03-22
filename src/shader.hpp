#ifndef SHADER_HPP_INCLUDED
#define SHADER_HPP_INCLUDED
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <memory>

#include "vulkan_include.hpp"

#include "logical_device.hpp"

namespace vkPost
{
    void createShaderModule(LogicalDevice* pLogicalDevice, const std::vector<char>& code, VkShaderModule* shaderModule);
    void createShaderModule(LogicalDevice* pLogicalDevice, const std::vector<uint32_t>& code, VkShaderModule* shaderModule);
} // namespace vkPost

#endif // SHADER_HPP_INCLUDED
