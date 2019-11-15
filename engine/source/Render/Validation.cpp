#include "../../includes/Render/RenderManager.hpp"

bool					RenderManager::checkValidationLayerSupport() {
	uint32_t layerCount;
	vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

	std::vector<VkLayerProperties> availableLayers(layerCount);
	vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

	for (const char* layerName : validationLayers) {
		bool layerFound = false;
		for (const auto& layerProperties : availableLayers) {
			if (strcmp(layerName, layerProperties.layerName) == 0) {
				layerFound = true;
				break;
			}
		}
		if (!layerFound) return false;
	}

	return true;
}

std::vector<const char*> RenderManager::getRequiredExtensions() {
	uint32_t glfwExtensionCount = 0;
	const char** glfwExtensions;
	printf("extensions\n");
	glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
	printf("extensions\n");
	std::vector<const char*> extensions(glfwExtensions, glfwExtensions + glfwExtensionCount);
	printf("extensions\n");

	if (enableValidationLayers) {
		extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
	}
	printf("extensions\n");

	return extensions;
}
