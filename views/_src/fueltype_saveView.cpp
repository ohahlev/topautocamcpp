#include <QtCore>
#include <TreeFrogView>
#include "fueltype.h" 
#include "applicationhelper.h"
#include "bodytypevalidator.h"
#include "colorvalidator.h"
#include "drivetypevalidator.h"
#include "fueltypevalidator.h"
#include "gradevalidator.h"
#include "makevalidator.h"
#include "newsvalidator.h"
#include "vehiclemodelvalidator.h"
#include "vehiclevalidator.h"

class T_VIEW_EXPORT fueltype_saveView : public TActionView
{
  Q_OBJECT
public:
  fueltype_saveView() : TActionView() { }
  QString toString();
};

QString fueltype_saveView::toString()
{
  responsebody.reserve(2708);
    tfetch(QVariantMap, fuelType);
  tfetch(QString, err_name);
  responsebody += QStringLiteral("<div class=\"container\">\n  <div class=\"row\">\n    <div class=\"col-lg-12\">\n      <div class=\"panel panel-primary\">\n        <div class=\"panel-heading\">\n          <h3 class=\"panel-title\">\n            <i class=\"fa fa-globe\"></i> Edit Fuel Type\n          </h3>\n        </div>\n        <div class=\"panel-grade\">\n          ");
  responsebody += QVariant(renderPartial("error")).toString();
  responsebody += QStringLiteral("\n          ");
  responsebody += QVariant(renderPartial("flash")).toString();
  responsebody += QStringLiteral("\n          <form class=\"form-horizontal\" method=\"POST\" action=\"/admin/fuel/save/");
  responsebody += THttpUtility::htmlEscape(fuelType["id"]);
  responsebody += QStringLiteral("\">\n            <fieldset class=\"container\">\n              <input type=\"text\" name=\"fuelType[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(fuelType["id"]);
  responsebody += QStringLiteral("\" style=\"display: none\"/>\n          <div class=\"form-group row is-empty\">\n            <label for=\"inputName\" autocomplete=\"false\" \n        class=\"col-lg-2 control-label\">Name</label>\n            <div class=\"col-lg-10\">\n              ");
  if(err_name == NULL) {
  responsebody += QStringLiteral("                <input type=\"text\" class=\"form-control is-valid\" id=\"inputName\" placeholder=\"name\" name=\"fuelType[name]\" value=\"");
  responsebody += THttpUtility::htmlEscape(fuelType["name"]);
  responsebody += QStringLiteral("\" />\n                ");
  } else {
  responsebody += QStringLiteral("                <input type=\"text\" class=\"form-control is-invalid\" id=\"inputName\" placeholder=\"name\" name=\"fuelType[name]\" value=\"");
  responsebody += THttpUtility::htmlEscape(fuelType["name"]);
  responsebody += QStringLiteral("\" />\n                <div class=\"invalid-feedback\">\n                  ");
  responsebody += THttpUtility::htmlEscape(err_name);
  responsebody += QStringLiteral("\n                </div>\n                ");
  };
  responsebody += QStringLiteral("              </div>\n            </div>\n            <div class=\"form-group row justify-content-end\">\n              <div class=\"col-lg-10\">\n                <button type=\"submit\" class=\"btn btn-raised btn-danger\">Save</button>\n                <a href=\"");
  responsebody += QVariant(urla("index")).toString();
  responsebody += QStringLiteral("\" class=\"btn btn-raised btn-info\">Cancel</a>\n              </div>\n            </div>\n          </fieldset>\n        </form>\n      </div>\n    </div>\n  </div>\n</div>\n</div>\n");

  return responsebody;
}

T_DEFINE_VIEW(fueltype_saveView)

#include "fueltype_saveView.moc"
