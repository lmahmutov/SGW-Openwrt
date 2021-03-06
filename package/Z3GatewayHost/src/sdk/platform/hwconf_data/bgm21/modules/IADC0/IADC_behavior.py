from . import ExporterModel
from . import IADC_model
from . import RuntimeModel


class IADC(ExporterModel.Module):
    def __init__(self, name=None):
        if not name:
            name = self.__class__.__name__
        super(IADC, self).__init__(name, visible=True, core=True)
        self.model = IADC_model

    def set_runtime_hooks(self):
        pass