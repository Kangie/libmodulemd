/* modulemd-metadata.c
 *
 * Copyright (C) 2017 Stephen Gallagher
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE X CONSORTIUM BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include "modulemd-modulemetadata.h"
#include <glib.h>
#include <yaml.h>

enum
{
    MD_PROP_0,

    //MD_PROP_API,
    //MD_PROP_ARTIFACTS,
    //MD_PROP_BUILDOPTS,
    //MD_PROP_BUILDREQUIRES,
    MD_PROP_COMMUNITY,
    //MD_PROP_COMPONENTS,
    //MD_PROP_CONTENT_LIC,
    MD_PROP_DESC,
    MD_PROP_DOCS,
    //MD_PROP_FILTER,
    //MD_PROP_MDVERSION,
    //MD_PROP_MODULE_LIC,
    MD_PROP_NAME,
    //MD_PROP_PROFILES,
    //MD_PROP_REQUIRES,
    MD_PROP_STREAM,
    MD_PROP_SUMMARY,
    MD_PROP_TRACKER,
    //MD_PROP_VERSION,
    //MD_PROP_XMD,

    MD_N_PROPERTIES
};

static GParamSpec *md_properties[MD_N_PROPERTIES] = { NULL, };

struct _ModulemdModuleMetadata
{
    GObject parent_instance;

    /* == Members == */
    // ModulemdModuleAPI *api;
    // ModulemdModuleArtifacts *artifacts;
    // ModulemdModuleBuildopts *buildopts;
    // GHashTable *buildrequires;
    gchar *community;
    // ModulemdModuleComponents *components;
    // gchar **content_licenses;
    gchar *description;
    gchar *documentation;
    // ModulemdModuleFilter *filter;
    // gint mdversion;
    // gchar **module_licenses;
    gchar *name;
    // GHashTable *profiles;
    // GHashTable *requires;
    gchar *stream;
    gchar *summary;
    gchar *tracker;
    // gint version;
    // GHashTable *xmd;
};

G_DEFINE_TYPE (ModulemdModuleMetadata, modulemd_modulemetadata, G_TYPE_OBJECT)

/**
 * modulemd_module_set_community:
 * @community: the module community.
 *
 * Sets the "community" property.
 */
void
modulemd_modulemetadata_set_community (ModulemdModuleMetadata *self,
                                       const gchar *community)
{
    g_return_if_fail (MODULEMD_IS_MODULEMETADATA (self));

    if (g_strcmp0(self->community, community) != 0) {
        g_free (self->community);
        self->community = g_strdup (community);
        g_object_notify_by_pspec (G_OBJECT(self),
                                  md_properties [MD_PROP_COMMUNITY]);
    }
}

/**
 * modulemd_module_get_community:
 *
 * Retrieves the "community" for modulemd.
 *
 * Returns: A string containing the "community" property.
 */
const gchar *
modulemd_modulemetadata_get_community (ModulemdModuleMetadata *self)
{
    g_return_val_if_fail (MODULEMD_IS_MODULEMETADATA (self), NULL);

    return self->community;
}

/**
 * modulemd_module_set_description:
 * @community: the module description.
 *
 * Sets the "description" property.
 */
void
modulemd_modulemetadata_set_description (ModulemdModuleMetadata *self,
                                         const gchar *description)
{
    g_return_if_fail (MODULEMD_IS_MODULEMETADATA (self));

    if (g_strcmp0(self->description, description) != 0) {
        g_free (self->description);
        self->description = g_strdup (description);
        g_object_notify_by_pspec (G_OBJECT(self),
                                  md_properties [MD_PROP_DESC]);
    }
}

/**
 * modulemd_module_get_description:
 *
 * Retrieves the "description" for modulemd.
 *
 * Returns: A string containing the "description" property.
 */
const gchar *
modulemd_modulemetadata_get_description (ModulemdModuleMetadata *self)
{
    g_return_val_if_fail (MODULEMD_IS_MODULEMETADATA (self), NULL);

    return self->description;
}

/**
 * modulemd_module_set_documentation:
 * @community: the module documentation.
 *
 * Sets the "documentation" property.
 */
void
modulemd_modulemetadata_set_documentation (ModulemdModuleMetadata *self,
                                           const gchar *documentation)
{
    g_return_if_fail (MODULEMD_IS_MODULEMETADATA (self));

    if (g_strcmp0(self->documentation, documentation) != 0) {
        g_free (self->documentation);
        self->documentation = g_strdup (documentation);
        g_object_notify_by_pspec (G_OBJECT(self),
                                  md_properties [MD_PROP_DOCS]);
    }
}

/**
 * modulemd_module_get_documentation:
 *
 * Retrieves the "documentation" for modulemd.
 *
 * Returns: A string containing the "documentation" property.
 */
const gchar *
modulemd_modulemetadata_get_documentation (ModulemdModuleMetadata *self)
{
    g_return_val_if_fail (MODULEMD_IS_MODULEMETADATA (self), NULL);

    return self->documentation;
}

/**
 * modulemd_module_set_name:
 * @community: the module name.
 *
 * Sets the "name" property.
 */
void
modulemd_modulemetadata_set_name (ModulemdModuleMetadata *self,
                                  const gchar *name)
{
    g_return_if_fail (MODULEMD_IS_MODULEMETADATA (self));

    if (g_strcmp0(self->name, name) != 0) {
        g_free (self->name);
        self->name = g_strdup (name);
        g_object_notify_by_pspec (G_OBJECT(self),
                                  md_properties [MD_PROP_NAME]);
    }
}

/**
 * modulemd_module_get_name:
 *
 * Retrieves the "name" for modulemd.
 *
 * Returns: A string containing the "name" property.
 */
const gchar *
modulemd_modulemetadata_get_name (ModulemdModuleMetadata *self)
{
    g_return_val_if_fail (MODULEMD_IS_MODULEMETADATA (self), NULL);

    return self->name;
}

/**
 * modulemd_module_set_stream:
 * @community: the module stream.
 *
 * Sets the "stream" property.
 */
void
modulemd_modulemetadata_set_stream (ModulemdModuleMetadata *self,
                                    const gchar *stream)
{
    g_return_if_fail (MODULEMD_IS_MODULEMETADATA (self));

    if (g_strcmp0(self->stream, stream) != 0) {
        g_free (self->stream);
        self->stream = g_strdup (stream);
        g_object_notify_by_pspec (G_OBJECT(self),
                                  md_properties [MD_PROP_STREAM]);
    }
}

/**
 * modulemd_module_get_stream:
 *
 * Retrieves the "stream" for modulemd.
 *
 * Returns: A string containing the "stream" property.
 */
const gchar *
modulemd_modulemetadata_get_stream (ModulemdModuleMetadata *self)
{
    g_return_val_if_fail (MODULEMD_IS_MODULEMETADATA (self), NULL);

    return self->stream;
}

/**
 * modulemd_module_set_summary:
 * @community: the module summary.
 *
 * Sets the "summary" property.
 */
void
modulemd_modulemetadata_set_summary (ModulemdModuleMetadata *self,
                                     const gchar *summary)
{
    g_return_if_fail (MODULEMD_IS_MODULEMETADATA (self));

    if (g_strcmp0(self->summary, summary) != 0) {
        g_free (self->summary);
        self->summary = g_strdup (summary);
        g_object_notify_by_pspec (G_OBJECT(self),
                                  md_properties [MD_PROP_SUMMARY]);
    }
}

/**
 * modulemd_module_get_summary:
 *
 * Retrieves the "summary" for modulemd.
 *
 * Returns: A string containing the "summary" property.
 */
const gchar *
modulemd_modulemetadata_get_summary (ModulemdModuleMetadata *self)
{
    g_return_val_if_fail (MODULEMD_IS_MODULEMETADATA (self), NULL);

    return self->summary;
}

static void
modulemd_modulemetadata_set_property (GObject *gobject,
                                      guint property_id,
                                      const GValue *value,
                                      GParamSpec *pspec)
{
    ModulemdModuleMetadata *self = MODULEMD_MODULEMETADATA(gobject);

    switch (property_id) {
    /* Simple string properties */
    case MD_PROP_COMMUNITY:
        modulemd_modulemetadata_set_community(self, g_value_get_string(value));
        break;
    case MD_PROP_DESC:
        modulemd_modulemetadata_set_description(self, g_value_get_string(value));
        break;
    case MD_PROP_DOCS:
        modulemd_modulemetadata_set_documentation(self, g_value_get_string(value));
        break;
    case MD_PROP_NAME:
        modulemd_modulemetadata_set_name(self, g_value_get_string(value));
        break;
    case MD_PROP_STREAM:
        modulemd_modulemetadata_set_stream(self, g_value_get_string(value));
        break;
    case MD_PROP_SUMMARY:
        modulemd_modulemetadata_set_summary(self, g_value_get_string(value));
        break;
    case MD_PROP_TRACKER:
        g_clear_pointer (&self->tracker, g_free);
        self->tracker = g_value_dup_string (value);
        break;

    default:
        G_OBJECT_WARN_INVALID_PROPERTY_ID (gobject, property_id, pspec);
        break;
    }
}

static void
modulemd_modulemetadata_get_property (GObject *gobject,
                                      guint property_id,
                                      GValue *value,
                                      GParamSpec *pspec)
{
    ModulemdModuleMetadata *self = MODULEMD_MODULEMETADATA(gobject);

    switch (property_id) {
    /* Simple string properties */
    case MD_PROP_COMMUNITY:
        g_value_set_string (value,
                            modulemd_modulemetadata_get_community(self));
        break;

    case MD_PROP_DESC:
        g_value_set_string (value,
                            modulemd_modulemetadata_get_description(self));
        break;

    case MD_PROP_DOCS:
        g_value_set_string (value,
                            modulemd_modulemetadata_get_documentation(self));
        break;

    case MD_PROP_NAME:
        g_value_set_string (value,
                            modulemd_modulemetadata_get_name(self));
        break;

    case MD_PROP_STREAM:
        g_value_set_string (value,
                            modulemd_modulemetadata_get_stream(self));
        break;

    case MD_PROP_SUMMARY:
        g_value_set_string (value,
                            modulemd_modulemetadata_get_summary(self));
        break;

    case MD_PROP_TRACKER:
        g_value_set_string (value, self->tracker);
        break;

    default:
        G_OBJECT_WARN_INVALID_PROPERTY_ID (gobject, property_id, pspec);
        break;
    }
}

static void
modulemd_modulemetadata_dispose (GObject *gobject)
{
    G_OBJECT_CLASS (modulemd_modulemetadata_parent_class)->dispose (gobject);
}

static void
modulemd_modulemetadata_finalize (GObject *gobject)
{
    ModulemdModuleMetadata *self = MODULEMD_MODULEMETADATA(gobject);
    g_clear_pointer (&self->name, g_free);

    G_OBJECT_CLASS (modulemd_modulemetadata_parent_class)->finalize (gobject);
}

static void
modulemd_modulemetadata_class_init (ModulemdModuleMetadataClass *klass)
{
    GObjectClass *object_class = G_OBJECT_CLASS (klass);

    object_class->set_property = modulemd_modulemetadata_set_property;
    object_class->get_property = modulemd_modulemetadata_get_property;

    object_class->dispose = modulemd_modulemetadata_dispose;
    object_class->finalize = modulemd_modulemetadata_finalize;

    md_properties[MD_PROP_COMMUNITY] =
	    g_param_spec_string ("community",
                             "Module Community",
                             "A string property representing a link to the "
                             "upstream community for this module.",
                             "",
                             G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);

    md_properties[MD_PROP_DESC] =
	    g_param_spec_string ("description",
                             "Module Description",
                             "A string property representing a detailed "
                             "description of the module.",
                             "",
                             G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);

    md_properties[MD_PROP_DOCS] =
	    g_param_spec_string ("documentation",
                             "Module Documentation",
                             "A string property representing a link to the "
                             "upstream documentation for this module.",
                             "",
                             G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);

    md_properties[MD_PROP_NAME] =
        g_param_spec_string ("name",
                             "Module Name",
                             "A string property representing the name of "
                             "the module.",
                             "",
                             G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);

    md_properties[MD_PROP_STREAM] =
	    g_param_spec_string ("stream",
                             "Module Stream",
                             "A string property representing the stream name "
                             "of the module.",
                             "",
                             G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);

    md_properties[MD_PROP_SUMMARY] =
	    g_param_spec_string ("summary",
                             "Module Short Description",
                             "A string property representing a short summary "
                             "of the module.",
                             "",
                             G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);

    md_properties[MD_PROP_TRACKER] =
	    g_param_spec_string ("tracker",
                             "Module Bug Tracker",
                             "A string property representing a link to the "
                             "upstream bug tracker for this module.",
                             "",
                             G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);

    g_object_class_install_properties (
        object_class,
        MD_N_PROPERTIES,
        md_properties);
}

static void
modulemd_modulemetadata_init (ModulemdModuleMetadata *self)
{
}

/**
 * modulemd_modulemetadata_new:
 *
 * Allocates a new #ModulemdModuleMetadata.
 *
 * Return value: a new #ModulemdModuleMetadata.
 */
ModulemdModuleMetadata *
modulemd_modulemetadata_new (void)
{
    ModulemdModuleMetadata *md;

    md = g_object_new (modulemd_modulemetadata_get_type(), NULL);
    return md;
}

/**
 * modulemd_modulemetadata_free:
 *
 * Frees a #ModulemdModuleMetadata.
 */
void
modulemd_modulemetadata_free (ModulemdModuleMetadata *md)
{
    g_object_unref(md);
}