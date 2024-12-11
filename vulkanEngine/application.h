#pragma once
#include <vulkan/vulkan.h>
#include <vector>
#include <optional>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#ifdef NDEBUG
	const bool enableValidationLayers = false;
#else
	const bool enableValidationLayers = true;
#endif

struct QueueFamilyIndices {
	std::optional<uint32_t> graphicsFamily;

	bool isComplete() {
		return graphicsFamily.has_value();
	}
};
const std::vector<const char*> validationLayers = {
	"VK_LAYER_KHRONOS_validation"
};

class HelloTriangleApplication {
public:
	void run() {
		initWindow();
		initVulkan();
		mainLoop();
		cleanup();
	}

private:
	const uint32_t WIDTH = 800;
	const uint32_t HEIGHT = 600;
	GLFWwindow* window;

	VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
	VkInstance instance;
	VkDevice device;
	VkQueue graphicsQueue;

	// main function's for run().
	void initWindow();
	void initVulkan();
	void mainLoop();
	void cleanup();

	void createInstance();
	void createLogicalDevice();

	bool checkValidationLayerSupport();

	void pickPhysicalDevice();
	int rateDeviceSuitability(VkPhysicalDevice device);

	bool isDeviceSuitable(VkPhysicalDevice device);
	QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);

};