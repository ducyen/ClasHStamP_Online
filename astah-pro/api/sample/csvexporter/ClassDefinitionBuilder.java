import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import com.change_vision.jude.api.inf.AstahAPI;
import com.change_vision.jude.api.inf.exception.LicenseNotFoundException;
import com.change_vision.jude.api.inf.exception.NonCompatibleException;
import com.change_vision.jude.api.inf.exception.ProjectLockedException;
import com.change_vision.jude.api.inf.exception.ProjectNotFoundException;
import com.change_vision.jude.api.inf.model.IAttribute;
import com.change_vision.jude.api.inf.model.IClass;
import com.change_vision.jude.api.inf.model.IConstraint;
import com.change_vision.jude.api.inf.model.IElement;
import com.change_vision.jude.api.inf.model.IGeneralization;
import com.change_vision.jude.api.inf.model.IModel;
import com.change_vision.jude.api.inf.model.INamedElement;
import com.change_vision.jude.api.inf.model.IOperation;
import com.change_vision.jude.api.inf.model.IPackage;
import com.change_vision.jude.api.inf.model.IParameter;
import com.change_vision.jude.api.inf.model.IRealization;
import com.change_vision.jude.api.inf.project.ProjectAccessor;

/**
 * Class to build class definition from selected project.
 */
public class ClassDefinitionBuilder {

    private static final String EMPTY_COLUMN = "";

    private String inputFile;
    
    /**
     * @param inputFile
     *            File to input
     */
    public ClassDefinitionBuilder(String inputFile) {
        this.inputFile = inputFile;
    }

    /**
     * Get class information.
     * 
     * @return Class information (String List stored in the List)
     * @throws LicenseNotFoundException
     *             License cannot be found 
     * @throws ProjectNotFoundException
     *             Project cannot be found
     * @throws NonCompatibleException
     *             Old Model Version (The version of API is older than the version of Astah that the project has been last edited with)
     * @throws ClassNotFoundException
     *             Cannot read some models
     * @throws IOException
     *             Input/Output error
     * @throws ProjectLockedException
     *             Project file has been locked
     */
    public List<List<String>> getContents()
            throws LicenseNotFoundException, ProjectNotFoundException, NonCompatibleException,
            IOException, ClassNotFoundException, ProjectLockedException, Throwable {

    	// Open a project. And get the model.
        ProjectAccessor prjAccessor = AstahAPI.getAstahAPI().getProjectAccessor();
        prjAccessor.open(inputFile);
        IModel iModel = prjAccessor.getProject();

        List<List<String>> contents = new ArrayList<List<String>>();
        contents.add(getHeader());

        // get all packages of the project.
        List<IPackage> iPackages = getAllPackages(iModel);

        // build the information for each package.
        for (IPackage iPackage : iPackages) {
            contents.addAll(getClassInfos(iPackage));
        }

        // close project.
        prjAccessor.close();

        return contents;
    }

    /**
     * Get header information.
     * @return Header information (String List)
     */
    private List<String> getHeader() {
        List<String> header = new ArrayList<String>();
        header.add("Class");
        header.add("Attribute/Operation");
        header.add("Definition");
        header.add("Generalization");
        header.add("Realization");
        return header;
    }

    /**
     * Get all packages in project.
     * @param project
     *            Project
     * @return Package list
     */
    private List<IPackage> getAllPackages(IModel project) {
        List<IPackage> packages = new ArrayList<IPackage>();
        packages.add(project);
        return getPackages(project, packages);
    }

    /**
     * How to get packages under Package recursively
     * @param iPackage
     *            Selected package
     * @param iPackages
     *            List of all stored packages
     * @return List of all stored packages
     */
    private List<IPackage> getPackages(IPackage iPackage, List<IPackage> iPackages) {
        INamedElement[] iNamedElements = iPackage.getOwnedElements();
        for (INamedElement iNamedElement : iNamedElements) {
            if (iNamedElement instanceof IPackage) {
                iPackages.add((IPackage) iNamedElement);
                getPackages((IPackage) iNamedElement, iPackages);
            }
        }
        return iPackages;
    }

    /**
     * Get class information in selected package.
     * @param iPackage
     *            Selected package
     * @return Class information (String List stored in the list)
     */
    private List<List<String>> getClassInfos(IPackage iPackage) {
        List<List<String>> classInfos = new ArrayList<List<String>>();
        List<IClass> classes = getIClasses(iPackage);
        for (IClass iClass : classes) {
            classInfos.addAll(getClassInfo(iClass));
        }
        return classInfos;
    }

    /**
     * Get classes in selected package.
     * @param iPackage
     *            Selected package
     * @return List of all stored classes
     */
    private List<IClass> getIClasses(IPackage iPackage) {
        List<IClass> iClasses = new ArrayList<IClass>();
        INamedElement[] iNamedElements = iPackage.getOwnedElements();
        for (INamedElement iNamedElement : iNamedElements) {
            if (iNamedElement instanceof IClass) {
                iClasses.add((IClass) iNamedElement);
            }
        }
        return iClasses;
    }

    /**
     * Get information of selected class.
     * @param iClass
     *            Selected class
     * @return Class information (Strings list stored in the list)
     */
    private List<List<String>> getClassInfo(IClass iClass) {
        List<List<String>> lines = new ArrayList<List<String>>();
        lines.add(getClassNameLine(iClass));
        lines.addAll(getAttributeLines(iClass));
        lines.addAll(getOperationLines(iClass));
        return lines;
    }

    /**
     * Get class name line.
     * @param iClass
     *            Class
     * @return Information of Class name lines (String list)
     */
    private List<String> getClassNameLine(IClass iClass) {
        List<String> line = new ArrayList<String>();
        line.add(getFullName(iClass));
        line.add(EMPTY_COLUMN);
        line.add(iClass.getDefinition());
        line.add(getSuperClass(iClass));
        line.add(getImplementation(iClass));
        return line;
    }

    /**
     * Get Realization interface names.
     * @param iClass
     *            Class
     * @return Interface Name
     */
    private String getImplementation(IClass iClass) {
        List<String> supplierFullNames = new ArrayList<String>();
        IRealization[] realizations = iClass.getClientRealizations();
        for (IRealization realization : realizations) {
            INamedElement supplier = realization.getSupplier();
            if (supplier instanceof IClass) {
                supplierFullNames.add(getFullName((IClass) supplier));
            }
        }
        return String.join(", ", supplierFullNames);
    }

    /**
     * Get generalization class names.
     * @param iClass
     *            Class
     * @return Class name
     */
    private String getSuperClass(IClass iClass) {
        List<String> superTypeFullNames = new ArrayList<String>();
        IGeneralization[] generalizations = iClass.getGeneralizations();
        for (IGeneralization generalization : generalizations) {
            IClass superClass = generalization.getSuperType();
            superTypeFullNames.add(getFullName(superClass));
        }
        return String.join(", ", superTypeFullNames);
    }

    /**
     * Get Class name as Full Path.
     * @param iClass
     *            Class
     * @return Class Name (Full Path)
     */
    private String getFullName(IClass iClass) {
    	StringBuilder sb = new StringBuilder();
        IElement owner = iClass.getOwner();
        while (owner != null && owner instanceof INamedElement && owner.getOwner() != null) {
            sb.insert(0, ((INamedElement) owner).getName() + "::");
            owner = owner.getOwner();
        }
        sb.append(iClass.getName());
        return sb.toString();
    }

    /**
     * Get all Attribute information.
     * @param iClass
     *            Class
     * @return All information of all attributes (String List stored in the list)
     */
    private List<List<String>> getAttributeLines(IClass iClass) {
        List<List<String>> lines = new ArrayList<List<String>>();
        IAttribute[] iAttributes = iClass.getAttributes();
        for (IAttribute iAttribute : iAttributes) {
            lines.add(getAttributeLine(iAttribute));
        }
        return lines;
    }

    /**
     * Get Attribute information.
     * @param iAttribute
     *            Attribute
     * @return Attribute information (String List)
     */
    private List<String> getAttributeLine(IAttribute iAttribute) {
        List<String> line = new ArrayList<String>();
        line.add(EMPTY_COLUMN);
        line.add(getAttributeSignature(iAttribute));
        line.add(iAttribute.getDefinition());
        line.add(EMPTY_COLUMN);
        line.add(EMPTY_COLUMN);
        return line;
    }

    /**
     * Get attribute signature.
     * @param iAttribute
     *            Attribute
     * @return Attribute signature
     */
    private String getAttributeSignature(IAttribute iAttribute) {
        String visibility = getVisibility(iAttribute);

        String name = iAttribute.getName();

        String type = iAttribute.getTypeExpression();

        String initValue = iAttribute.getInitialValue();
        if (initValue.length() > 0) {
            initValue = " = " + initValue;
        }

        IConstraint[] constraints = iAttribute.getConstraints();
        String constraint = "";
        for (IConstraint iConstraint : constraints) {
            constraint = constraint + "{" + iConstraint.getName() + "}";
        }

        return visibility + " " + name + " : " + type + initValue + constraint;
    }

    /**
     * Get all operation information.
     * @param iClass
     *            Class
     * @return All operation information (String list stored in the list)
     */
    private List<List<String>> getOperationLines(IClass iClass) {
        List<List<String>> lines = new ArrayList<List<String>>();
        IOperation[] iOperations = iClass.getOperations();
        for (IOperation iOperation : iOperations) {
            lines.add(getOperationLine(iOperation));
        }
        return lines;
    }

    /**
     * Get operation information.
     * @param iOperation
     *            Operation
     * @return Operation information (String List)
     */
    private List<String> getOperationLine(IOperation iOperation) {
        List<String> line = new ArrayList<String>();
        line.add(EMPTY_COLUMN);
        line.add(getOperationSignature(iOperation));
        line.add(iOperation.getDefinition());
        line.add(EMPTY_COLUMN);
        line.add(EMPTY_COLUMN);
        return line;
    }

    /**
     * Get operation signature.
     * @param iOperation
     *            Operation
     * @return Operation signature
     */
    private String getOperationSignature(IOperation iOperation) {
        String param = "";

        IParameter[] parameters = iOperation.getParameters();
        for (int i = 0; i < parameters.length; i++) {
            String paramName = parameters[i].getName();
            String paramType = parameters[i].getTypeExpression();
            param = param + paramName + " : " + paramType;
            if (i != parameters.length - 1) {
                param += ", ";
            }
        }
        param = "(" + param + ")";

        IConstraint[] constraints = iOperation.getConstraints();
        String constraint = "";
        for (IConstraint iConstraint : constraints) {
            constraint = constraint + "{" + iConstraint.getName() + "}";
        }

        String visibility = getVisibility(iOperation);
        String name = iOperation.getName();
        String returnType = iOperation.getReturnTypeExpression();
        if (returnType.length() > 0) {
            return visibility + " " + name + param + " : " + returnType;
        } else {
            return visibility + " " + name + param;
        }
    }

    /**
     * Get visibility as string.
     * @param iNamedElement
     *            Named elements
     * @return Visibility
     */
    private String getVisibility(INamedElement iNamedElement) {
        if (iNamedElement.isPackageVisibility()) {
            return "package";
        } else if (iNamedElement.isProtectedVisibility()) {
            return "protected";
        } else if (iNamedElement.isPrivateVisibility()) {
            return "private";
        } else if (iNamedElement.isPublicVisibility()) {
            return "public";
        }
        return "";
    }
}
