#ifndef COMMAND_BUFFER_HPP_INCLUDED
#define COMMAND_BUFFER_HPP_INCLUDED
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <memory>

#include "vulkan_include.hpp"

#include "logical_device.hpp"

#include "effect.hpp"
namespace vkPost
{

    std::vector<VkCommandBuffer> allocateCommandBuffer(LogicalDevice* pLogicalDevice, uint32_t count);

    void writeCommandBuffers(LogicalDevice*                                 pLogicalDevice,
                             std::vector<std::shared_ptr<vkPost::Effect>> effects,
                             VkImage                                        depthImage,
                             VkImageView                                    depthImageView,
                             VkFormat                                       depthFormat,
                             std::vector<VkCommandBuffer>                   commandBuffers);

    std::vector<VkSemaphore> createSemaphores(LogicalDevice* pLogicalDevice, uint32_t count);
} // namespace vkPost

#endif // COMMAND_BUFFER_HPP_INCLUDED
